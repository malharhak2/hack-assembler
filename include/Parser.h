#ifndef PARSER_H
#define PARSER_H
#include <vector>

class Parser
{
    public:
        Parser();
        virtual ~Parser();

        vector<string> lines;

        void readLine(string line);
    protected:
    private:
};

#endif // PARSER_H
