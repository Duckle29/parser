#pragma once

using namespace std;

typedef void (*handler)(char *);

static handler m_codes[1000];
static handler g_codes[1000];

static void G00(char *input)
{
    cout << "G00: rapid linear move; passed substring: " << input << endl;
}

static void G01(char *input)
{
    cout << "G01: linear move; passed substring: " << input << endl;
}

static void G02(char* input)
{
    cout << "G02: clockwise arc; passed substring: " << input << endl;
}

static void G03(char* input)
{
    cout << "G03: counter-clockwise arc; passed substring: " << input << endl;
}

static void unknown(char* input)
{
    cout << "whoopsie! unknown or unsupported command" << endl;
}

static void assign_codes()
{
    for(int i = 0; i < 1000; i++)
    {
        g_codes[i] = unknown;
    }

    g_codes[0] = G00;
    g_codes[1] = G01;
    g_codes[2] = G02;
    g_codes[3] = G03;
}
