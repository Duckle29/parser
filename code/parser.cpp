#include "parser.h"



bool parser::is_int(char *input)  // int may contain an initial + or minus and an arbitrary amount of 0s
{    
    if((!isdigit(input[0]) && input[0]  != '-' && input[0] != '+'))
    {       
        return 0;
    }
    input++;    
    while(input[0] != '\0')
    {        
        if(!isdigit(input[0]))
        {
            return 0;
        }
        input++;
    }    
    return 1;
}

bool parser::is_float(char *input)
{   
    bool has_decimal = false;
    
    if((!isdigit(input[0]) && input[0]  != '-' && input[0] != '+'))
    {       
        return 0;
    }
    input++;

    while(input[0] != '\0')
    {     
        if(!has_decimal)
        {            
            if(!isdigit(input[0]) && input[0] != '.')
            {
                cout << "test" << endl;
                return 0;
            }
            has_decimal = 1;
        }
        else
        {            
            if(!isdigit(input[0]))
            {                    
                return 0;
            }
            
        }

        input++;        
    }
    return 1;
}

char *parser::tokenize(char *&input) // strip token and return as pointer
{      
    static char token[255];
    memset(token, '\0', 255);

    strncpy(token, input, strcspn(input+1, "NMGXYZF")+1);   
    
    
    


    input += strlen(token);
    
    
    return token;
}

bool parser::pass_chsm(char *&input)
{
    if(input[0] == 'N')
    {
        char *recv = strpbrk(input, "*")+1;

        int recv_chsm = atoi(recv);
        
        char *chsm = strtok(input, "*");
        static int calc_chsm = 0;

        for (int i = 0; i < strlen(chsm); i++)
        {
            
            calc_chsm ^= chsm[i];
        }

        char *line = tokenize(input);

        if(!is_int(line+1))
        {
            cout << "N not int: " << line << endl;
            return 0;
        }
        
        // store N number? 


        cout << calc_chsm << endl;
        return (calc_chsm == recv_chsm);        
    }

    
    return 1;
}

void parser::strip_spaces(char *&input)
{ 
    int i = 0, j = 0; 
    while (input[i]) 
    { 
        if (input[i] != ' ') 
        {
            input[j++] = input[i];             
        }
        i++;             
    } 
    input[j] = '\0'; 
    
}


bool parser::parse(char *input)
{
    strip_spaces(input);
    if(pass_chsm(input))
    {
        //cout << "Checksum pass" << endl;

        int code = -1;
        CodeType typ = UNKNOWN; 

        char *charcode = tokenize(input);    
        if(!is_float(charcode+1))
        {
            cout << "is not float: " << charcode << endl;
            return 0;
        }    

        if(charcode[0] == 'G')
        {
            typ = G_CODE;

            g_codes[atoi(charcode+1)](input);  
            return 1;
        }
        else if(charcode[0] == 'M')
        {
            typ = M_CODE;
            m_codes[atoi(charcode+1)](input);  
            return 1;
        }
        else
        {
            return 0;
        }       
    }
    else
    {
        cout << "Checksum fail" << endl;
        return 0;
    }    
}

parser::parser()
{
    assign_codes();
}