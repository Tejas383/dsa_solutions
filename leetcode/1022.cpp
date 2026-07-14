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

// Approach Name: Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  int DFS(TreeNode* root, int val) {
    if (!root) return 0;

    val = (val << 1) + root->val;
    if (!root->left && !root->right) return val;

    return DFS(root->left, val) + DFS(root->right, val);
  }

 public:
  int sumRootToLeaf(TreeNode* root) { return DFS(root, 0); }
};