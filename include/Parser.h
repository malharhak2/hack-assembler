#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <string>
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
        ifstream sourceCode;

        // Opens the input file and gets ready for parsing
        Parser(string filename);
        virtual ~Parser();

        // Are there more commands in the input?
        public bool hasMoreCommands();
        // Advance one line in the source
        public void advance();
        /* Returns the current command type */
        public CommandTypes commandType();
        // Returns the symbol or decimal Xxx of the current command @Xxx or (Xxx). Should be called only when commandType() if A_COMMAND or L_COMMAND.
        public string symbol();
        // Returns the dest mnemonic in the current C-command. Should be called only when commandType() is C_COMMAND
        public string dest();
        // Returns the comp mnemonic in the current C-cmomand.
        public string comp();
        // Returns the jump mnemonic in the current C-command.
        public string jump();
    protected:
    private:
};

#endif // PARSER_H
