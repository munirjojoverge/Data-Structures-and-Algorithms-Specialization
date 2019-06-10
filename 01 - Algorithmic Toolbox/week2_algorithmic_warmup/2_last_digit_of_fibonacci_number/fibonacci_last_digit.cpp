/*
Munir Jojo-Verge
04/07/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week2_algorithmic_warmup
			2_last_digit_of_fibonacci_number
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

	int previous = 0;
	int current  = 1;

    for (int i = 2; i <= n; ++i) {
		int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() {
	long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
