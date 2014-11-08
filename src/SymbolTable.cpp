#include "SymbolTable.h"
#include <iostream>
using namespace std;
SymbolTable::SymbolTable()
{
    // Sets the starting address
    curAddress = 16;
    // Fills the default symbols
    addEntry("SP",      0);
    addEntry("LCL",     1);
    addEntry("ARG",     2);
    addEntry("THIS",    3);
    addEntry("THAT",    4);

    addEntry("R0",      0);
    addEntry("R1",      1);
    addEntry("R2",      2);
    addEntry("R3",      3);
    addEntry("R4",      4);
    addEntry("R5",      5);
    addEntry("R6",      6);
    addEntry("R7",      7);
    addEntry("R8",      8);
    addEntry("R9",      9);
    addEntry("R10",      10);
    addEntry("R11",      11);
    addEntry("R12",      12);
    addEntry("R13",      13);
    addEntry("R14",      14);
    addEntry("R15",      15);

    addEntry("SCREEN",  16384);
    addEntry("KBD",     24576);

}
// Adds an entry to the symbol table
void SymbolTable::addEntry(string symbol, int address) {
    if (!contains(symbol)) {
        if (address == -1) {
            address = getNewAddress();
        }
        symbols[symbol] = address;
       cout << "Symbol " << symbol << " | " << address << " added." << endl;
    }
}
// Check if symbol exists
bool SymbolTable::contains(string symbol) {
    map<string, int>::const_iterator it = symbols.find(symbol);
    return it!= symbols.end();
}
// Address lookup for a symbol
int SymbolTable::getAddress(string symbol) {
    int address = symbols[symbol];
    //cout << "checking address for " << symbol << " (" << address << ")" << endl;
    return address;
}
// Generates a new address
int SymbolTable::getNewAddress() {
    //cout << "Generating new address: " << curAddress << endl;
    return curAddress++; // Increments address for next time
}
SymbolTable::~SymbolTable()
{

}
