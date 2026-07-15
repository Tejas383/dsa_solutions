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

// Approach Name: Recursive DFS (Binary Search Tree Insertion)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
      root = new TreeNode(val);
      return root;
    }

    if (val < root->val) 
      root->left = insertIntoBST(root->left, val);
    if (val > root->val) 
      root->right = insertIntoBST(root->right, val);

    return root;
  }
};