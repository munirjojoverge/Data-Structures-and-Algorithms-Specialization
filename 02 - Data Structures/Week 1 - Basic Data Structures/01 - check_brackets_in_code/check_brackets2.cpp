/*
Munir Jojo - Verge
04 / 14 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 1 - Basic Data Structures
			01 - check_brackets_in_code
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
        }
    }

    // Printing answer, write your code here

    return 0;
}
