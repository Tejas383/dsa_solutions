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

// Approach Name: Recursive Depth-First Search (DFS) with Backtracking
// Time Complexity: O(h)
// Space Complexity: O(h)

class Solution {
  vector<vector<int>> ans;

  void dfs(TreeNode* root, int target, vector<int>& path) {
    if (!root) return;

    path.push_back(root->val);
    target -= root->val;

    if (!root->left && !root->right) {
      if (target == 0) ans.push_back(path);
    }

    dfs(root->left, target, path);
    dfs(root->right, target, path);
    path.pop_back();
  }

 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    dfs(root, targetSum, path);
    return ans;
  }
};