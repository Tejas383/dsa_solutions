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

// Approach Name: Level Order Traversal using Queue
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int bottomLeft = root->val;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int s = q.size();
      bottomLeft = q.front()->val;

      while (s--) {
        auto curr = q.front();
        q.pop();

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }

    return bottomLeft;
  }
};