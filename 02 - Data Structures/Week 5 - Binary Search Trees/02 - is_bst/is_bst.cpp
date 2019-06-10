/*
Munir Jojo - Verge
04 / 21 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 5 - Binary Search Trees
			02 - is_bst
*/

// Only for Visual Studio implementation
//#include "stdafx.h"


#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define MY_INT_MIN     (-2147483647 - 1) // minimum (signed) int value
#define MY_INT_MAX       2147483647    // maximum (signed) int value



struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};



bool isBSTUtil(const vector<Node>& tree, const int &node_idx, int min, int max)
{
	
	/* an empty tree is BST */
	if (node_idx == -1)
		return true;

	/* false if this node violates the min/max constraint */
	if (tree[node_idx].key < min || tree[node_idx].key > max)
		return false;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return
		isBSTUtil(tree, tree[node_idx].left, min, tree[node_idx].key) &&  // Allow only distinct values
		isBSTUtil(tree, tree[node_idx].right, tree[node_idx].key, max);  // Allow only distinct values
}

bool IsBinarySearchTree(const vector<Node>& tree) {
	// Implement correct algorithm here
	/* an empty tree is BST */
	if (tree.size() == 0)
		return  true;
	
	return isBSTUtil(tree, 0, MY_INT_MIN, MY_INT_MAX);
	
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
