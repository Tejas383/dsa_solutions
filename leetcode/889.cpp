#include <bits/stdc++.h>
using namespace std;

// Approach name: Recursion using Preorder and Postorder Traversal
// Time complexity : O(n)
// Space complexity : O(n)

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
  unordered_map<int, int> indices;

  TreeNode* helper(int preStart, int preEnd, int postStart, int postEnd,
                   auto& preorder, auto& postorder) {
    if (preStart >= preEnd || postStart >= postEnd) return nullptr;

    int val = preorder[preStart];

    if (preStart + 1 >= preEnd) return new TreeNode(val);

    int idx = indices[preorder[preStart + 1]];
    int leftSize = idx - postStart + 1;
    TreeNode* left = helper(preStart + 1, preStart + leftSize + 1, postStart,
                            postStart + leftSize + 1, preorder, postorder);
    TreeNode* right =
        helper(preStart + leftSize + 1, preEnd, postStart + leftSize,
               postEnd - 1, preorder, postorder);

    return new TreeNode(val, left, right);
  }

 public:
  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    int n = preorder.size();

    for (int i = 0; i < n; i++) indices[postorder[i]] = i;

    return helper(0, n, 0, n, preorder, postorder);
  }
};