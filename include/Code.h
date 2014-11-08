#ifndef CODE_H
#define CODE_H
using namespace std;
#include <string>
#include <map>
/*
 * Code processing module: Returns the binary code for instructions
 */
class Code
{
    public:
        Code();
        virtual ~Code();

        // Returns the binary code of the dest mnemonic
        string dest(string mnemonic);
        // Returns the binary code of the comp mnemonic
        string comp(string mnemonic);
        // Returns the binary code of the jump mnemonic
        string jump(string mnemonic);

        map<string, string> comps;
        map<string, string> jumps;
        map<string, string> dests;
    protected:
    private:
};

#endif // CODE_H
