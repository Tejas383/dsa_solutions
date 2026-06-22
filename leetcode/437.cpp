#include <bits/stdc++.h>
using namespace std;

// Approach Name: Prefix Sum + Hash Map + DFS (Backtracking)
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
 public:
  int dfs(TreeNode* root, int target, unordered_map<long long, int>& freq,
          long long sum) {
    if (!root) return 0;

    sum += root->val;
    int tot = 0;
    if (sum == target) tot++;

    long long diff = sum - target;
    if (freq.count(diff)) tot += freq[diff];

    freq[sum]++;
    int left = dfs(root->left, target, freq, sum);
    int right = dfs(root->right, target, freq, sum);
    freq[sum]--;

    return left + right + tot;
  }

  int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> freq;

    int ans = dfs(root, targetSum, freq, 0);

    return ans;
  }
};