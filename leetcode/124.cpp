#include <bits/stdc++.h>
using namespace std;

// Approach Name: Postorder DFS
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
  int sum = INT_MIN;

  // Returns the maximum path sum starting from the current node and extending
  // downward to either the left or right child.
  int dfs(TreeNode* root) {
    if (!root) return 0;

    // If a subtree contributes a negative sum, ignore it.
    int left = max(dfs(root->left), 0);
    int right = max(dfs(root->right), 0);

    // Maximum path passing through the current node.
    // This path may include both left and right children.
    sum = max(sum, root->val + left + right);

    // Return the best downward path starting from the current node.
    // We can choose only one child because the parent cannot branch.
    return root->val + max(left, right);
  }

 public:
  int maxPathSum(TreeNode* root) {
    dfs(root);
    return sum;
  }
};