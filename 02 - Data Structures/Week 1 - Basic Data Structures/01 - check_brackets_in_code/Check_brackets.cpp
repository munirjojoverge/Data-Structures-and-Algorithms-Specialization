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
#include <sstream>
#include <stack>

using namespace std;
struct stack_Item
{
	char Bracket_Type;
	int str_idx; // This will store the Index on the Original String where the "Bracket" was found
};

string Is_Balanced(string str) {
	stack<stack_Item> checking_stack;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
			stack_Item item;
			item.Bracket_Type = str[i];
			item.str_idx = i;
			checking_stack.push(item);
		}
		else if (str[i] == ']' || str[i] == '}' || str[i] == ')') 
		{
				if (checking_stack.empty()) return  std::to_string(i + 1);
				stack_Item top = checking_stack.top();
				checking_stack.pop();
				if ((top.Bracket_Type == '[' && str[i] != ']') ||
					(top.Bracket_Type == '{' && str[i] != '}') ||
					(top.Bracket_Type == '(' && str[i] != ')'))
					return  std::to_string(i +1);
		}
	}

	return (checking_stack.empty() ? "Success" : std::to_string(checking_stack.top().str_idx + 1));
}

int main()
{
	string str;

	//cout << "Please enter a valid sentence (with spaces):\n>";
	getline(cin, str);

	cout << Is_Balanced(str) << endl;

	return 0;
}