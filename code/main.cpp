#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

#include "parser.h"
#include "functions.h"


using namespace std;
using namespace std::chrono;

int main()
{
    parser parser;

    
    

    char input[256] = "G03 X3.777 Y-11.786 E0.01530";
    char copy[256];

    strncpy(copy, input, 256); 

   
    if(parser.parse(input))
    {
        cout << "Successfully parsed input." << endl;
    }
    else
    {
        cout << "Error while parsing: Check input string" << endl;
    }
    


    cout << "done." << endl;
    return 0;
}