/*
Munir Jojo - Verge
04 / 11 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week5_dynamic_programming1
			3_edit_distance
To solve this algorithm I found this video very helpful:
https://www.youtube.com/watch?v=We3YDTzNXEk
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
	
	//vector<int> Rows(str1.length() + 1);
	//vector<Rows>(str2.length() + 1);
	vector<vector<int>> D((str1.length()+1), std::vector<int>(str2.length()+1));
	// Let's initialize the first ROW and the first COL
	//vector<vector<int>::iterator> v(D.size());
	//std::iota(v.begin(), v.end(), 0);

	for (size_t i = 0; i < str1.length() + 1; i++)
	{
		D[i][0] = i;
	}
	for (size_t j = 0; j < str2.length() + 1; j++)
	{
		D[0][j] = j;
	}

	

	for (size_t i = 1; i < str1.length()+1; i++)
	{
		for (size_t j = 1; j < str2.length()+1; j++)
		{
			if (str1[i-1] == str2[j-1]) {
				D[i][j] = D[i - 1][j - 1];
			}
			else {
				D[i][j] = min(min(D[i][j - 1], D[i - 1][j - 1]), D[i - 1][j]) + 1;
			}
		}
	}

  return D[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
