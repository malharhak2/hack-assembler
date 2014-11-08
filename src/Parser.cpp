#include "Parser.h"
using namespace std;
#include <string>
Parser::Parser(string filename)
{
    // Opens the file and starts
    sourceCode.open(filename.c_str());
    if (sourceCode.is_open()) {

    } else {
        cout << "Could not open source file" << endl;
    }
}
void Parser::readLine() {
    getline(sourceCode, line);
    line = removeWhitespace(line);
}

bool Parser::hasMoreCommands() {
    //cout << "checking commands" << endl;
    // If there's a new line continue, otherwise return
    if (getline(sourceCode, line)) {
        return advance();
    } else {
        return false;
    }
}
bool Parser::advance() {
    line = removeWhitespace(line);
    if (line.find("//") != string::npos) {
        // Strips the comment
        line = line.substr(0, line.find("//"));
    }
    if (line.find("@") == 0) {
        // This is a A-instruction
        command = A_COMMAND;
        return true;
    } else if (line.find("(") == 0) {
        // This is a L-COMMAND (label)
        command = L_COMMAND;
        return true;
    } else if (line.find("=") != string::npos || line.find(";") != string::npos) {
        // This is a C command by default
        command = C_COMMAND;
        return true;
    } else { // If nothing is found, go next line
        return hasMoreCommands();
    }
}

CommandTypes Parser::commandType() {
    return command;
}
string Parser::symbol() {
    // Checks for the @
    if (line.find("@") != string::npos) {
        return line.substr(1);
    } else {
        return line.substr(1, line.length() - 2);
    }
}
string Parser::dest() {

    if (line.find("=") == string::npos) {
        return "null";
    } else {
        return line.substr(0, line.find("="));
    }
}
string Parser::jump() {
    if (line.find(";") == string::npos) {
        return "null";
    } else {
        return line.substr(line.find(";") + 1);
    }
}
string Parser::comp() {
    int start = 0;
    int finish = line.length();
    if (line.find("=") != string::npos) {
        start = line.find("=") + 1;
    }
    if (line.find(";") != string::npos) {
        finish = line.find(";");
    }
    // gets the "middle" of the command"
    return line.substr(start, finish - start);
}
Parser::~Parser()
{
    sourceCode.close();
    delete sourceCode;
    //dtor
}

// Just to remove spaces..
string Parser::removeWhitespace (string str) {
    str.erase (remove (str.begin(), str.end(), ' '), str.end());

    return str;
}
