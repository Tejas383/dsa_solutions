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

// Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Approach Name: Breadth-First Search (BFS) with Horizontal Distance Mapping
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> bottomView(Node* root) {
    // code here
    map<int, int> mp;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      Node* node = curr.first;
      int col = curr.second;

      mp[col] = node->data;

      if (node->left) q.push({node->left, col - 1});
      if (node->right) q.push({node->right, col + 1});
    }

    vector<int> ans;
    for (auto p : mp) {
      ans.push_back(p.second);
    }

    return ans;
  }
};