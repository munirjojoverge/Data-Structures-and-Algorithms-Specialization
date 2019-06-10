/*
Munir Jojo-Verge
04/07/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week2_algorithmic_warmup
			5_fibonacci_number_again
*/

// Only for Visual Studio implementation
#include "stdafx.h"

#include <iostream>

long long int get_fibonacci_mod(long long int n, long long int m) {
    if (n <= 1)
        return n;

    long long int previous = 0;
    long long int current  = 1;

    for (long long i = 2; i <= n ; ++i) {
        long long int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

long long int get_pisano_period(long long m) {
	long long int a = 0, b = 1, c = a + b;
	for (long long int i = 0; i < m * m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1) 
			return i + 1;
	}
}

long long int get_fibonacci_huge_opt(long long int n, long long int m) {
	long long int period = get_pisano_period(m);
	
	// reminder
	long long int reminder = n % period;

	return get_fibonacci_mod(reminder, m);

}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_opt(n, m) << '\n';
}
