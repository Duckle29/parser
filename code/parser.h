#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

#include "functions.h"

using namespace std;

enum CodeType {
    UNKNOWN = 0,
    G_CODE,
    M_CODE
    };

class Parser
{
    private:
	bool is_int(char *input);
	bool is_float(char *input);
	void strip_spaces(char *&input);
	bool pass_chsm(char *&input);

    public:
	Parser();
        char *tokenize(char *&input);
        bool parse(char *input);
        void assign_codes();
};
