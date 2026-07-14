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

// Approach Name: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  int dia = 0;

  int height(TreeNode* root) {
    if (!root) return 0;

    return max(height(root->left), height(root->right)) + 1;
  }

 public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    dia = max(dia, leftHeight + rightHeight);

    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);

    return dia;
  }
};