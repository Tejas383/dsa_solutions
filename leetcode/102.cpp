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

// Approach Name: Iterative BFS (using Queue)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int s = q.size();
      vector<int> vec;

      while (s--) {
        auto curr = q.front();
        q.pop();

        vec.push_back(curr->val);

        if (curr->left) 
          q.push(curr->left);
        if (curr->right) 
          q.push(curr->right);
      }

      ans.push_back(vec);
    }

    return ans;
  }
};