#include <vector>
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

// Approach Name: Recursive DFS (Preorder)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  TreeNode* invert(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* node = new TreeNode(root->val);
    if (root->left) 
      node->right = invert(root->left);
    if (root->right) 
      node->left = invert(root->right);

    return node;
  }

  TreeNode* invertTree(TreeNode* root) { 
    return invert(root); 
  }
};