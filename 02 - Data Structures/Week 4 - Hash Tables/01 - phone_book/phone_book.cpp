/*
Munir Jojo - Verge
04 / 20 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 4 - Hash Tables
			01 - phone_book
			Requirement: Use direct Addressing. i.e. use an array of size = max number of phone entries with 10^7. (0 to 999,999)
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>
#include <string>
#include <array>

using std::string;
using std::vector;
using std::cin;

struct Query {
	string type;
	string name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        } else if (queries[i].type == "del") {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        } else {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}
/*
vector<string> process_queries_direct_address(const vector<Query>& queries) {
	vector<string> result;
	// Keep list of all existing (i.e. not deleted yet) contacts.
	const long long contacts_size = 10000000;
	//string contacts[contacts_size][15];
	//char contacts[contacts_size][15];
	//std::array<std::string, 100000> contacts;
	//std::array<Query, 10000000> contacts2;
	vector<string> contacts(contacts_size);

	for (size_t i = 0; i < queries.size(); ++i)
		if (queries[i].type == "add") {
			auto result = std::find(contacts.begin(), contacts.end(), queries[i].name);
			if (result != contacts.end())
			{
				contacts[queries[i].number] = queries[i].name;
			}
			else
			{
				contacts.begin();
			}
			contacts[queries[i].number] = queries[i].name;
		}
		else if (queries[i].type == "del") {
			contacts[queries[i].number] = "";
		}
		else {
			if (contacts[queries[i].number] == "")
				result.push_back("not found");
			else
				result.push_back(contacts[queries[i].number]);
		}
		return result;
}
*/
vector<string> process_queries_direct_address2(const vector<Query>& queries) {
	vector<string> result;
	// Keep list of all existing (i.e. not deleted yet) contacts.
	const int contacts_size = 10000000;
	//string contacts[contacts_size];
	//char contacts[contacts_size][15];
	//std::array<std::string, 100000> contacts;
	//std::array<Query, 10000000> contacts2;
	vector<string> contacts(contacts_size);

	for (size_t i = 0; i < queries.size(); ++i)
		if (queries[i].type == "add") {
			contacts[queries[i].number] = queries[i].name;
		}
		else if (queries[i].type == "del") {
			contacts[queries[i].number] = "";
		}
		else {
			if (contacts[queries[i].number] == "")
				result.push_back("not found");
			else
				result.push_back(contacts[queries[i].number]);
		}
		return result;
}


int main() {
    write_responses(process_queries_direct_address2(read_queries()));
    return 0;
}
