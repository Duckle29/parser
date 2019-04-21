#pragma once

#include "functions.h"

#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <stdlib.h>

using namespace std;

enum CodeType {
    UNKNOWN = 0,
    G_CODE,
    M_CODE
    }; 

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