/*
Munir Jojo-Verge
04/07/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week2_algorithmic_warmup
			6_last_digit_of_the_sum_of_fibonacci_numbers
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long int get_fibonacci_mod(long long int n, long long int m) {
	if (n <= 1)
		return n;

	long long int previous = 0;
	long long int current = 1;

	for (long long i = 2; i <= n; ++i) {
		long long int tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % m;
	}

	return current;
}

size_t get_pisano_period2(long long m) {
	std::vector<long> v{ 1, 1 };
	while (true) {
		auto t = (v[v.size() - 1] + v[v.size() - 2]) % m;
		v.push_back(t);
		if (t == 0 && v.size() % 2 == 0 &&
			std::equal(v.begin(), v.begin() + v.size() / 2,
				v.begin() + v.size() / 2, v.end())) {
			return v.size() / 2;
		}
	}
	return v.size() / 2;
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

int fibonacci_sum_opt(long long int n)
{
	return (get_fibonacci_huge_opt(n + 2, 100) - 1) % 10 ;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_opt(n) << std::endl;
}
