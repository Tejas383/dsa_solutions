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

// Approach Name: Recursive DFS with Left-Leaf Tracking
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  int sum(TreeNode* root, bool isLeft) {
    if (!root) return 0;

    if (!root->left && !root->right)
      if (isLeft)
        return root->val;
      else
        return 0;

    return sum(root->left, true) + sum(root->right, false);
  }

  int sumOfLeftLeaves(TreeNode* root) { 
    return sum(root, false); 
  }
};