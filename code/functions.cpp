#include "functions.h"
#include <iostream>
using namespace std;

void G01(char *input)
{
    cout << "G01: linear move; passed substring: " << input << endl;
}

void unknown(char *input)
{
    cout << "Whoopsie! Unknown Command!" <<  endl;
}