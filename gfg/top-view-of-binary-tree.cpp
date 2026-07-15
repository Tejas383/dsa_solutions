#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// Approach Name: Breadth-First Search (BFS) with Horizontal Distance Mapping
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> topView(Node* root) {
    // code here
    map<int, vector<int>> mp;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      Node* node = curr.first;
      int col = curr.second;

      mp[col].push_back(node->data);

      if (node->left) q.push({node->left, col - 1});
      if (node->right) q.push({node->right, col + 1});
    }

    vector<int> ans;
    for (auto p : mp) {
      ans.push_back(p.second[0]);
    }

    return ans;
  }
};