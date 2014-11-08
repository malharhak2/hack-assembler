#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <Parser.h>
#include <Code.h>
#include <SymbolTable.h>
using namespace std;

string removeWhitespace (string str) {
    str.erase (remove (str.begin(), str.end(), ' '), str.end());

    return str;
}

int main(int argc, char* argv[])
{
    // Gets command line argument for file to process
    string filename = argv[1];

    cout << filename << endl;
    cout << "Hello world!" << endl;

    // First pass: Look for symbol and adds them to the table
    string line;
    ifstream symbolReader(filename.c_str());
    SymbolTable* table = new SymbolTable();
    int counter = 0;
    while (getline(symbolReader, line)) {
            line = removeWhitespace(line);
        if (line.find("//") != string::npos) { // If there is a comment, strip it
            line = line.substr(0, line.find("//"));
        }
        if (line.find("(") != string::npos) { // If this is a symbol declaration
            string symbol = line.substr(1, line.find(")") - 1);
            //cout << "Adding symbol: " << symbol << endl;
            table->addEntry(symbol, counter);
            // Don't increment counter because it's not an instruction
        } else if (line.find("@") != string::npos) { // If this is a @ instruction
//            int ch = (int)line.at(1);
//            if (isalpha(ch)) { // If first character is alpha, it's a symbol
//                string symbol = line.substr(1, line.length() - 1); // Gets the symbol name
//                table->addEntry(symbol, -1); // -1  tells the table to generate new address
//            }
// Actually, @ symbols are added on the second pass
            counter++; // Increments the counter for any @inst
        } else if (line.find(";") != string::npos || line.find("=") != string::npos) {
            // If it is a C instruction, increment counter too
            counter++;
        }
    }
    symbolReader.close();
    delete symbolReader; // Don't need it anymore
    Parser* parser = new Parser(filename); // Starts actually parsing the code
    Code* code = new Code();
    string finalString;
    while (parser->hasMoreCommands()) {
        //cout << parser->line << endl;
        if (parser->commandType() == A_COMMAND) {
            // Stores the found symbol
            string ori_symbol = parser->symbol();
            //cout << parser->symbol() << endl;
            int symbol;
            // if symbol is a variable, get its address from the symbol table
            if (isalpha((int)ori_symbol.at(0))) {
                if (!table->contains(ori_symbol)) {
                   table->addEntry(ori_symbol, -1);
                }
                symbol = table->getAddress(ori_symbol);
            } else {
                symbol = atoi(ori_symbol.c_str());
            }
            // Creates a binary representation of the value
            bitset<15> bin_symbol(symbol);
            string val = bin_symbol.to_string();
            //cout << bin_symbol << endl;
            // Adds the symbol to the final code
            finalString = finalString + "0" + val + "\n";

        }
        // C instruction, just combines the three components
        if (parser->commandType() == C_COMMAND) {
            finalString = finalString + "111" + code->comp(parser->comp())
                        + code->dest(parser->dest())
                        + code->jump(parser->jump())
                        + "\n";

            if (parser->jump() != "null") {
                //cout << "Jump: " << parser->jump() << endl;
            }
            if (parser->dest() != "null") {
                //cout << "Dest: " << parser->dest() << endl;
            }
            //cout << "Comp: " << parser->comp() << endl;

        }
    }
    // Create the output .hack file
    string outputFile = filename.substr(0, filename.length() - 4);
    outputFile = outputFile + ".hack";
    ofstream hackFile(outputFile.c_str());
    hackFile << finalString; // Writes the final code to the file
    hackFile.close();
    cout << "Compilation finished successfully!" << endl;
    delete hackFile;
    //cout << finalString << endl;
    delete parser;
    delete code;
    delete table;
    return 0;
}


