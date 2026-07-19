#include <bits/stdc++.h>
using namespace std;

// Approach Name: Parent Mapping + BFS
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();

      if (curr->left) {
        parent[curr->left] = curr;
        q.push(curr->left);
      }
      if (curr->right) {
        parent[curr->right] = curr;
        q.push(curr->right);
      }
    }

    q.push(target);
    unordered_set<TreeNode*> vis;
    vis.insert(target);
    while (!q.empty() && k) {
      int s = q.size();

      while (s--) {
        TreeNode* curr = q.front();
        q.pop();

        if (parent.count(curr) && !vis.contains(parent[curr])) {
          q.push(parent[curr]);
          vis.insert(parent[curr]);
        }
        if (curr->left && !vis.contains(curr->left)) {
          q.push(curr->left);
          vis.insert(curr->left);
        }
        if (curr->right && !vis.contains(curr->right)) {
          q.push(curr->right);
          vis.insert(curr->right);
        }
      }

      k--;
    }

    vector<int> ans;
    while (!q.empty()) {
      ans.push_back(q.front()->val);
      q.pop();
    }

    return ans;
  }
};