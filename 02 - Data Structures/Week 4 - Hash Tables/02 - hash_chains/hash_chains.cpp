/*
Munir Jojo - Verge
04 / 20 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 4 - Hash Tables
			02 - hash_chains
*/

// Only for Visual Studio implementation
//#include "stdafx.h"



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <array>

using std::string;
using std::vector;
using std::cin;

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
	vector<list<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (( (hash * multiplier + s[i]) % prime) + prime) % prime;
        return hash % bucket_count;
    }

public:
	explicit QueryProcessor(int bucket_count) {
		this->bucket_count = bucket_count;
		list<string> l;// = { "" };
		for (size_t i = 0; i < bucket_count; i++)
		{
			this->elems.push_back(l);
		}
	}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
			if (query.ind < elems.size()) {
				auto L = elems[query.ind];
				for (auto s : L) {
					std::cout << s << " ";
				}
				std::cout << endl;
			}
        } 
		else {
			size_t hash_idx = hash_func(query.s);
			auto it = std::find(elems[hash_idx].begin(), elems[hash_idx].end(), query.s);
			if (query.type == "find")
				writeSearchResult(it != elems[hash_idx].end());
			else if (query.type == "add") {
				if (it == elems[hash_idx].end())
					elems[hash_idx].push_front(query.s);
			}
			else if (query.type == "del") {
				if (it != elems[hash_idx].end())
					elems[hash_idx].erase(it);
			}

        }
    }



    void processQueries() {
        int n;
        cin >> n;
		vector<Query> queries(n);
		for (int i = 0; i < n; ++i)
			queries[i] = readQuery();

		for (int i = 0; i < n; ++i)
            processQuery(queries[i]);
		std::cout << endl;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
