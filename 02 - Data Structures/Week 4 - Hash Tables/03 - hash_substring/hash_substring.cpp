/*
Munir Jojo - Verge
04 / 21 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 4 - Hash Tables
			03 - hash_substring
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using std::string;
using namespace std::chrono;
using namespace std;

typedef unsigned long long ull;


struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (int i = output.size()-1; i >= 0; --i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}

ull hash_func(const string& s,const ull &prime, const ull &x)
{
	unsigned long long hash = 0;
	for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
		//hash = (((hash * x + s[i]) % prime) + prime) % prime;
		hash = (hash * x + s[i]) % prime;
	return hash; // % bucket_count;
}

std::vector<ull> PrecomputeHash(const string& T, const string& t_substr, const size_t &pattern_size, const ull &prime, const ull &x)
{
	size_t text_size = T.size();
	vector<ull> H(text_size - pattern_size + 1);

	H[text_size - pattern_size] = hash_func(t_substr, prime, x);
	
	
	ull y = 1;
	for (size_t i = 1; i <= pattern_size; ++i)
	{
		y = (y * x) % prime;
	}
	

	for (int i = text_size - pattern_size - 1; i >= 0; --i)
	{
		H[i] = (ull)(((H[i + 1] * x) + T[i] - (y * T[i + pattern_size])) % prime);
		//H[i] = (ull)((H[i] + prime) % prime);
		//H[i] = (((H[i + 1] * x + T[i]) % prime - (y * T[i + pattern_size]) % prime) + prime) % prime;
	}
	return H;
}

void RibinKarp(const Data& input) {
	// parse the input;
	const string& p = input.pattern, t = input.text;

	/*The hash functions should be selected at random, but once and for all keys. 
	If we select a random hash function again for each key x we want to hash, 
	this will be a non-deterministic hash function, which is not useful.
	*/
	ull prime = 100000007; // We can try bigger prime numbers to minimize the probability of missing the substring and false alarms/false positives.
	ull x = 1;
	// We could just select an X from 1 to prime-1, but we can also Randomize it
	//std::srand(std::time(0)); //use current time as seed for random generator
	
	/*
	while (x > (prime-1))
		//x = ((double)rand() / (RAND_MAX)) * prime
		x = 1 + std::rand() / ((RAND_MAX + 1u) / (prime-1));  // Note: 1+rand()%(prime-1) is biased
	*/
    //x = ull(((double)rand() / (RAND_MAX)) * (prime-1));

	// initializing the answer list
	//std::vector<int> ans;


	// LET'S START THE FIND THE PATTERNS
	size_t pattern_size = p.size();
	size_t text_size = t.size();

	ull pattern_hash = hash_func(p, prime, x);
	string t_substr = t.substr(text_size - pattern_size, pattern_size);

	std::vector<ull> H = PrecomputeHash(t, t_substr, pattern_size, prime, x);
	
	//t_substr = t.substr(0, pattern_size);
	for (int i = 0 ; i <= text_size - pattern_size; ++i)
	{
		//t_substr = t.substr(i, pattern_size);
		if ((H[i] == pattern_hash) && (t.substr(i, pattern_size).compare(p) == 0)) {
				//ans.push_back(i);
			std::cout << i << " ";
		}
		
		//t_substr = t[i - 1] + t_substr.erase(pattern_size - 1, 1);
		//t_substr = t_substr.erase(0, 1) + t[i + pattern_size];
		//t_substr = t[0:3];
		//t.substr(i, pattern_size);
	}

	/*
	if ((H[text_size - pattern_size] == pattern_hash) && (t_substr.compare(p) == 0)) {
		//ans.push_back(0);
		std::cout << (text_size - pattern_size) << " ";
	}
	*/
	std::cout << std::endl;

	//return ans;

}

int main() 
{
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    //print_occurrences(RibinKarp(read_input()));
	RibinKarp(read_input());
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();

	//double duration = double(duration_cast<microseconds>(t2 - t1).count()/1000000);

	//std::cout << duration << std::endl;
    return 0;
}
