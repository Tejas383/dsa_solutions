#include <algorithm>
#include <climits>
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

// Approach Name: DFS (Recursive Depth-First Search)
// Time Complexity: O(n)
// Space Complexity: O(h)

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    if (!root->left && !root->right) return 1;

    int left = INT_MAX;
    int right = INT_MAX;
    if (root->left) left = minDepth(root->left);
    if (root->right) right = minDepth(root->right);

    return min(left, right) + 1;
  }
};