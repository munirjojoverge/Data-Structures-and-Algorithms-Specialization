/*
Munir Jojo-Verge
04/07/2018
Coursera
00-Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week2_algorithmic_warmup
			1_fibonacci_number	
*/

// Only for Visual Studio implementation
#include "stdafx.h"

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;


// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(const int n) {
    // write your code here
	/*
	I'll just start doing it like a human would do. I'll start storing only 2 integers n_1 and n_2.
	and go forward.
	*/
	int fib_n, fib_n_1=1, fib_n_2=0;
	if (n <= 1)
		return n;

	for (int i = 2; i <= n; i++)
	{
		fib_n = fib_n_1 + fib_n_2;
		fib_n_2 = fib_n_1;
		fib_n_1 = fib_n;
	}
    return fib_n;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
	/*
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
    std::cout << fibonacci_naive(n) << '\n';
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << " duration: " << duration << "\n";
	*/

    //test_solution();
	//t1 = high_resolution_clock::now();
	std::cout << fibonacci_fast(n) << '\n';
	//t2 = high_resolution_clock::now();

	//duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << " duration: " << duration << "\n";
    return 0;
}
