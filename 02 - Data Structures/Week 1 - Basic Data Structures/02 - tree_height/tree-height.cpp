/*
Munir Jojo - Verge
04 / 14 / 2018
Coursera
00 - Algorithms and Data Structures
	02 - Data Structures
		Week 1 - Basic Data Structures
			02 - tree_height
*/

// Only for Visual Studio implementation
//#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

Node find_root(std::vector<Node> &nodes) {
	
	// Since there is guarantee that we have root (problem statement) then we should not worry about initializing 
	// the return value
	for (Node n : nodes) {
		if (n.parent == NULL)
			return n;
	}
}

int branch_max_height(Node node) {
	int max_height = 0;
	if (node.children.empty())
		return 1;

	for (size_t i = 0; i < node.children.size(); i++)
	{
		int height = branch_max_height(*(node.children[i]));
		max_height = std::max(max_height, height);
	}
	max_height++;

	return max_height;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  
  // Replace this code with a faster implementation
  int maxHeight = 0;
  /*
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }
    */

  // My initial though is to find the Root and later use a recurse algorithm to find the max depth/height
  Node root = find_root(nodes);

  maxHeight = branch_max_height(root);
  std::cout << maxHeight << std::endl;
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
