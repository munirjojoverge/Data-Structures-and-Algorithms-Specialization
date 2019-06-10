/*
Munir Jojo-Verge
04/08/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week3_greedy_algorithms
			1_money_change
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <array>

int get_change(int m) {
  //write your code here
	std::array<int, 3> coins { 10, 5, 1 };
	int coins_given = 0;
	int current_coin = 0; // index
	while (m > 0)
	{
		coins_given += int(m / coins[current_coin]);
		m = m % coins[current_coin];
		current_coin++;
	}
  return coins_given;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
