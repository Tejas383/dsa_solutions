#include <bits/stdc++.h>
using namespace std;

// Approach Name: DFS with Path Maximum Tracking
// Time complexity = O(n)
// Space complexity = O(h)
// where,
// n = number of nodes
// h = height of the tree

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

class Solution {
  int count = 0;

  void dfs(TreeNode* root, int maxVal) {
    if (!root) return;

    if (root->val >= maxVal)
      count++;

    dfs(root->left, max(maxVal, root->val));
    dfs(root->right, max(maxVal, root->val));
  }

 public:
  int goodNodes(TreeNode* root) {
    dfs(root, root->val);

    return count;
  }
};