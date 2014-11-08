#ifndef CODE_H
#define CODE_H


class Code
{
    public:
        Code();
        virtual ~Code();

        // Returns the binary code of the dest mnemonic
        public string dest(string mnemonic);
        // Returns the binary code of the comp mnemonic
        public string comp(string mnemonic);
        // Returns the binary code of the jump mnemonic
        public string jump(string mnemonic);
    protected:
    private:
};

#endif // CODE_H
