/*
Munir Jojo - Verge
04 / 08 / 2018
Coursera
00 - Algorithms and Data Structures
	01 - Algorithmic Toolbox
		week3_greedy_algorithms
			4_collecting_signatures
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
  bool operator<(const Segment& s) const
  {
	  return ((start < s.start) || ((start == s.start) & (end < s.end)));
  }
  bool operator==(const Segment& s) const
  {
	  return ((start == s.start) & (end == s.end));
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  //write your code here
  int i = 0;
  while (i < segments.size()) {
	  int min_end = segments[i].end;

	  int j = i + 1;
	  while ((j < segments.size()) && (segments[j].start)<= min_end)
	  {
		  min_end = std::min(min_end, segments[j].end);
		  j++;
	  }
	  points.push_back(min_end);
	  i = j;
  }
  return points;
}




int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;

  }

  // Sort the Vector by "start"
  std::sort(segments.begin(), segments.end());
 /* 
  std::cout << "Ordered" << "\n";
  for (int i = 0; i < segments.size(); ++i) {
	  std::cout << i << " - "  << segments[i].start << " " << segments[i].end << "\n";
  }
  std::cout << "\n";
  */
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
