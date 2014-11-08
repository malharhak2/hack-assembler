#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Parses the code for easy access
 */
 enum CommandTypes {
    A_COMMAND, // @Xxx command where Xxx is either a symbol or a decimal number
    C_COMMAND, // dest=comp;jump
    L_COMMAND  // Pseudo-command for (Xxx) where Xxx is a symbol
 };

class Parser
{
    public:
        /* VARIABLES
        *============
        */
        // File container for the source to assemble
        ifstream sourceCode;
        // String containing the current line we're processing
        string line;
        // Stores the current command type
        CommandTypes command;


        /* FUNCTIONS
        *============
        */
        // Opens the input file and gets ready for parsing
        Parser(string filename);
        virtual ~Parser();
        // Takes a new line in the file and reads it to line
        void readLine();

        // Are there more commands in the input?
        bool hasMoreCommands();
        // Advance one line in the source
        bool advance();
        /* Returns the current command type */
        CommandTypes commandType();
        // Returns the symbol or decimal Xxx of the current command @Xxx or (Xxx). Should be called only when commandType() if A_COMMAND or L_COMMAND.
        string symbol();
        // Returns the dest mnemonic in the current C-command. Should be called only when commandType() is C_COMMAND
        string dest();
        // Returns the comp mnemonic in the current C-cmomand.
        string comp();
        // Returns the jump mnemonic in the current C-command.
        string jump();

        string removeWhitespace(string str);
    protected:
    private:
};

#endif // PARSER_H
