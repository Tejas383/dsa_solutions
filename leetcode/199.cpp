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

// Approach Name: Breadth-First Search (BFS) / Level Order Traversal using Queue
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return vector<int>();

    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int s = q.size();
      int value;

      while (s--) {
        TreeNode* curr = q.front();
        q.pop();

        value = curr->val;

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }

      ans.push_back(value);
    }

    return ans;
  }
};