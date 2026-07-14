#include <bits/stdc++.h>
using namespace std;

// Definition for Node
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

// Link: https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// Approach Name: Breadth-First Search (BFS) with Horizontal Distance Mapping
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<vector<int>> verticalOrder(Node* root) {
    // code here
    map<int, vector<int>> vertical;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      Node* node = curr.first;
      int col = curr.second;

      vertical[col].push_back(node->data);

      if (node->left) {
        q.push({node->left, col - 1});
      }
      if (node->right) {
        q.push({node->right, col + 1});
      }
    }

    vector<vector<int>> ans;
    for (auto p : vertical) {
      auto vec = p.second;
      ans.push_back(vec);
    }

    return ans;
  }
};