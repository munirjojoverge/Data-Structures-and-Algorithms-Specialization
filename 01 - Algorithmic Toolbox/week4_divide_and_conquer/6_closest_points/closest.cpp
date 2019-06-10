/*
Munir Jojo - Verge
04 / 10 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week4_divide_and_conquer
			6_closest_points
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
using namespace std;

#define MY_DBL_MAX          1.7976931348623158e+308 // max value

struct point {
	int x, y;
};


bool sort_x(const point& p1, const point& p2)
{
	return (p1.x < p2.x);
}

bool sort_y(const point& p1, const point& p2)
{
	return (p1.y < p2.y);
}

double distance(const point& p1, const point& p2)
{
	long long dist_x = (long long)(p1.x) - p2.x;
	long long dist_y = (long long)(p1.y) - p2.y;
	return sqrt((dist_x * dist_x) + (dist_y * dist_y));
}

// A Brute Force method to return the smallest distance between two points

double bruteForce(vector<point> points)
{
	double min_d = MY_DBL_MAX;
	int n = points.size();
	for (size_t i = 0; i < n; i++)
		for (size_t j = i + 1; j < n; ++j) {
			double dist = distance(points[i], points[j]);
			if (dist < min_d)
				min_d = dist;
		}
	return min_d;
}


double minimal_distance(vector<point> points) {
  //write your code here
	double d = MY_DBL_MAX;
	if (points.size() <= 4)
		return bruteForce(points);

	// SORT BY X COORDINATE
	std::sort(points.begin(), points.end(),sort_x);

	// DIVIDE IN HALF THE SET
	size_t half = points.size() / 2;
	
	// CREATE THE 2 SUB-SETS S1 AND S2
	vector<point> S1;
	S1.insert(S1.begin(), points.begin(), points.begin() + half + 1);

	vector<point> S2;
	S2.insert(S2.begin(), points.begin() + half + 1, points.end());

	// MAKE THE RECURSIVE CALL => CALCULATE THE SHORTEST DISTANCE OF EACH SET
	double d1 = minimal_distance(S1);
	double d2 = minimal_distance(S2);

	 d = min(d1, d2);

	//FIND MIDDLE LINE X BETWEEN S1 AND S2
	int S1_last_x = S1[S1.size() - 1].x;
	int S2_first_x = S2[0].x;
	double middle_x = S1_last_x + (double(S2_first_x) - S1_last_x) / 2.0;

	// FILTER FROM THEN ENTIRE SET ONLY THOSE WITH AN X COORDINATE WITH DISTANCE TO MIDDLE_X <= d
	vector<point> filter_points;
	for (size_t i = 0; i < points.size(); i++)
	{
		if (abs(points[i].x - middle_x) < d)
			filter_points.push_back(points[i]);
	}

	std::sort(filter_points.begin(), filter_points.end(), sort_y);


	for (size_t i = 0; i < filter_points.size(); i++)
	{
		for (size_t j = i+1; ( (j < i+7) && (j < filter_points.size())); j++)
		{
			double dist = distance(filter_points[i], filter_points[j]);
			if (dist < d)
				d = dist;
		}
	}



  return d;
}

int Random_n() {
	//int random_number = std::experimental::randint(100, 999);
	//return 2 + std::rand() / ((RAND_MAX + 2u) / 200000);
	
	long long x = 1000000000;
	while (x > 1000000000) {
		std::srand(std::time(nullptr)); // use current time as seed for random generator
		x = (long long)(std::rand())%2000000000 - 1000000000;  // Note: 1+rand()%6 is wrong!
	}
	return int(x);
}

void Random_values(const int n, vector<point>& points) {

	int i = 0;
	while (i < n) {
		point pt;
		pt.x = 2;
		pt.y = Random_n();
		std::cout << pt.x << " " << pt.y << endl;
		points.push_back(pt);
		i++;
	}
}

int main() {

	/*
	size_t n;
	vector<point> points;
	cout << "Generate Random test data? [Y/N]: ";
	char Random;
	cin >> Random;
	switch (Random)
	{
	case 'Y':
	{
			
		//n = Random_n();
		n = 10;
		std::cout << n << endl;
		Random_values(n, points);
		break;
	}
	default:
	{
		std::cin >> n;
		point pt;
		for (size_t i = 0; i < n; i++) {
			std::cin >> pt.x >> pt.y;
			points.push_back(pt);
		}
		break;
	}
	}
  */
	size_t n;
	std::cin >> n;
	vector<point> points;
	point pt;
	for (size_t i = 0; i < n; i++) {
		std::cin >> pt.x >> pt.y;
		points.push_back(pt);
	}
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points) << "\n";
}
