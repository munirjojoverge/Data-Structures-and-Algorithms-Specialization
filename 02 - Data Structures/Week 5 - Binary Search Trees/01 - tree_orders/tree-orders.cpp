/*
Munir Jojo - Verge
04 / 21 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 5 - Binary Search Trees
			01 - tree_orders
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_node(vector <int> &result, int node) {
	  if (node == -1)
		  return;
	  else
	  {
		  in_order_node(result, this->left[node]);
		  result.push_back(this->key[node]);
		  in_order_node(result, this->right[node]);
	  }
  }

  void pre_order_node(vector <int> &result, int node) {
	  if (node == -1)
		  return;
	  else
	  {
		  result.push_back(this->key[node]);
		  pre_order_node(result, this->left[node]);
		  pre_order_node(result, this->right[node]);
	  }
  }

  void post_order_node(vector <int> &result, int node) {
	  if (node == -1)
		  return;
	  else
	  {
		  post_order_node(result, this->left[node]);
		  post_order_node(result, this->right[node]);
		  result.push_back(this->key[node]);
	  }
  }

  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
	in_order_node(result, 0);
	
    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
	pre_order_node(result, 0);

    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
	post_order_node(result, 0);

    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

