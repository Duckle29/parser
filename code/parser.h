#pragma once

class parser
{
    private:
    bool is_int(char *input);
    bool is_float(char *input);
    void strip_spaces(char *&input);
    bool pass_chsm(char *&input);

    public: 
        char *tokenize(char *&input);
        bool parse(char *input);
        void assign_codes();
};