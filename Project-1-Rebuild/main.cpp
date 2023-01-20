#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <termios.h>
#include <unistd.h>
#include "StoredWebPages.h"
#include "StringIntMap.h"
#include "StoredWords.h"


using namespace std;

/* Some ANSI terminal commands you can print to clear screen and change colors */
string clear_screen = "\e[2J\e[H";
string color_red = "\e[31;40m";
string color_green = "\e[32;40m";
string color_yellow = "\e[33;40m";
string color_blue = "\e[34;40m";
string color_magenta = "\e[35;40m";
string color_cyan = "\e[36;40m";
string color_white = "\e[37;40m";
string color_whiteblue = "\e[37;44m";
string background_blue = "\e[44;1m";
string reset_background = "\e[40m";

void predict(const string &query);

string readWebpagesFast(const char *filename);

void processKeystrokes();

int main() {
    processKeystrokes();
    return 0;
}

/* TODO IMPLEMENT */
void predict(const string &query) {
    cout << color_green << "Next word: '"
         << color_white << "query"
         << color_green << "'\n";
    /* TEST CODE */
}

string readWebpagesFast(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, "Error: can't open %s", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buff = new char[size + 1];
    buff[size] = 0;
    int dummy_result = fread(buff, size, 1, fp);
    fclose(fp);
    string result(buff);
    delete[] buff;
    return result;
}

void processKeystrokes() {
    int ch = 0;
    string query;
    while (ch != '\n') {
        cout << clear_screen << color_green << "Search keyword: "
             << color_white << query
             << color_green << "-\n\n";
        cout << color_yellow << "'" << "Place holder text" << color_green << "' pages match"
             << endl;
        predict(query);
        cout << flush;

        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (ch == 8 || ch == 127) { // backspace
            if (query.length() > 0) query = query.substr(0, query.length() - 1);
        } else if (ch != ' ' && ch != '\n') query += ch;
    }
    cout << color_white;
}
