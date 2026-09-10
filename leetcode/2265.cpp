#include <bits/stdc++.h>
using namespace std;

// Approach: Postorder Tree Traversal (DFS) using Subtree Sum & Node Count
// Time Complexity: O(n)
// Space Complexity: O(h) — recursion stack, where h is the height of the tree.

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
  // helper = {sum of subtree, nodes in subtree}
  pair<int, int> helper(TreeNode* root) {
    if (!root) return {0, 0};

    auto left = helper(root->left);
    auto right = helper(root->right);

    int sum = left.first + right.first + root->val;
    int nodes = left.second + right.second + 1;
    int avg = sum / nodes;

    if (root->val == avg) {
      count++;
    }

    return {sum, nodes};
  }

 public:
  int averageOfSubtree(TreeNode* root) {
    helper(root);
    return count;
  }
};