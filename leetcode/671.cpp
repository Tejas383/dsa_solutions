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

// Approach Name: DFS
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  long long first = LLONG_MAX;
  long long second = LLONG_MAX;

  void find(TreeNode* root) {
    if (!root) return;

    if (root->val < first) {
      second = first;
      first = root->val;
    } else if (root->val < second && root->val != first)
      second = root->val;

    find(root->left);
    find(root->right);
  }

 public:
  int findSecondMinimumValue(TreeNode* root) {
    find(root);

    return (second <= INT_MAX) ? second : -1;
  }
};