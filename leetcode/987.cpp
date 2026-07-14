#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Approach Name: Breadth-First Search (BFS) with Column-Row Mapping and
// Multiset Time Complexity: O(n) Space Complexity: O(n)

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    // mp<row, map<col, vec>>

    queue<pair<TreeNode*, pair<int, int>>> q;
    // q<node, {row, col}>
    q.push({root, {0, 0}});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      auto node = curr.first;
      int col = curr.second.first;
      int row = curr.second.second;

      mp[col][row].insert(node->val);

      if (node->left) q.push({node->left, {col - 1, row + 1}});
      if (node->right) q.push({node->right, {col + 1, row + 1}});
    }

    vector<vector<int>> ans;
    for (auto p : mp) {
      vector<int> vec;
      for (auto q : p.second)
        vec.insert(vec.end(), q.second.begin(), q.second.end());
      ans.push_back(vec);
    }

    return ans;
  }
};