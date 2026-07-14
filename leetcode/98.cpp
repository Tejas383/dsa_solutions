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

// Approach Name: Recursive DFS with Min-Max Range Validation
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
  bool validate(TreeNode* root, int minVal, int maxVal) {
    if (!root) return true;

    if (root->val <= minVal || root->val >= maxVal) 
      return false;

    return validate(root->left, minVal, root->val) &&
           validate(root->right, root->val, maxVal);
  }

 public:
  bool isValidBST(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
  }
};