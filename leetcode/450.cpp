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

// Approach Name: Recursive DFS (Binary Search Tree Deletion using Inorder Successor) 
// Time Complexity: O(h) 
// Space Complexity: O(h)

class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else {
      if (!root->left && !root->right)
        root = nullptr;
      else if (!root->right)
        root = root->left;
      else if (!root->left)
        root = root->right;
      else {
        TreeNode* node = root->right;
        while (node->left) node = node->left;
        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
      }
    }

    return root;
  }
};