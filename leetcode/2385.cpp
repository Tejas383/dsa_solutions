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

// Approach Name: Single-Pass Recursive DFS (Height + Distance Propagation)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  int ans = 0;

  int dfs(TreeNode* root, int start) {
    if (!root) return 0;

    int left = dfs(root->left, start);
    int right = dfs(root->right, start);

    if (root->val == start) {
      ans = max(left, right);
      return -1;
    }

    if (left < 0) {
      ans = max(right - left, ans);
      return left - 1;
    }

    if (right < 0) {
      ans = max(left - right, ans);
      return right - 1;
    }

    return max(left, right) + 1;
  }

 public:
  int amountOfTime(TreeNode* root, int start) {
    if (!root) return 0;

    dfs(root, start);
    return ans;
  }
};