#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
using namespace std;
#include <string>
#include <map>

class SymbolTable
{
    public:
        int curAddress;
        SymbolTable();
        void addEntry(string symbol, int address);
        bool contains (string symbol);
        int getAddress (string symbol);
        int getNewAddress ();

        map<string, int> symbols;
        virtual ~SymbolTable();
    protected:
    private:
};

#endif // SYMBOLTABLE_H
