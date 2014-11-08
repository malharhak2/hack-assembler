#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string line;
    string out;
    ifstream sourceCode ("program.asm");
    if (sourceCode.is_open()) {
        while (getline (sourceCode, line)) {
            processLine(line);
            cout << line << '\n';
        }
        sourceCode.close();
    } else {
        cout << "Unable to open file";
    }
    return 0;
}


string processLine (string line) {

}
