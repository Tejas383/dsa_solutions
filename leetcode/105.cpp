#include <bits/stdc++.h>
using namespace std;

// Approach name: Recursion using Preorder and Inorder Traversal
// Time complexity : O(n^2)
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
  TreeNode* helper(int preStart, int preEnd, int inStart, int inEnd,
                   auto& preorder, auto& inorder) {
    if (preStart >= preEnd || inStart >= inEnd) return nullptr;

    int val = preorder[preStart];

    int idx = inStart;
    // finding the index of root in inorder
    while (inorder[idx] != val) idx++;

    // finding the size of left subtree
    int leftSize = idx - inStart;

    // we have taken the root, so it won't be taken again

    // for the left subtree, we need the preorder form curr preorder start index
    // + 1 to the size of the left subtree
    TreeNode* left = helper(preStart + 1, preStart + leftSize + 1, inStart, idx,
                            preorder, inorder);
    TreeNode* right = helper(preStart + leftSize + 1, preEnd, idx + 1, inEnd,
                             preorder, inorder);

    return new TreeNode(val, left, right);
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    return helper(0, n, 0, n, preorder, inorder);
  }
};

// Approach name: Recursion + Hash Map for Inorder Indices
// Time complexity : O(n) average
// Space complexity : O(n)

class Solution {
  unordered_map<int, int> indices;
  // to store the indices of the nodes (inorder)

  TreeNode* helper(int preStart, int preEnd, int inStart, int inEnd,
                   auto& preorder, auto& inorder) {
    if (preStart >= preEnd || inStart >= inEnd) return nullptr;

    int val = preorder[preStart];
    int idx = indices[val];
    int leftSize = idx - inStart;

    TreeNode* left = helper(preStart + 1, preStart + leftSize + 1, inStart, idx,
                            preorder, inorder);
    TreeNode* right = helper(preStart + leftSize + 1, preEnd, idx + 1, inEnd,
                             preorder, inorder);

    return new TreeNode(val, left, right);
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; i++) indices[inorder[i]] = i;

    return helper(0, n, 0, n, preorder, inorder);
  }
};