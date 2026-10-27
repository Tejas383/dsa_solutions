#include <bits/stdc++.h>
using namespace std;

// Approach: DFS (Depth-First Search) + Subtree Counting
// Time Complexity: \(O(n)\)
// Space Complexity: \(O(n)\) — recursion stack in the worst case.

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
  TreeNode* find(TreeNode* root, int val) {
    if (!root) return nullptr;

    if (root->val == val) return root;

    TreeNode* left = find(root->left, val);

    if (left) return left;

    return find(root->right, val);
  }

  int count(TreeNode* node) {
    if (!node) return 0;

    return 1 + count(node->left) + count(node->right);
  }

 public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    TreeNode* node = find(root, x);

    int left = !node ? 0 : count(node->left);
    int right = !node ? 0 : count(node->right);
    int parent = n - left - right - 1;

    return (left > right + parent || right > left + parent ||
            parent > left + right);
  }
};