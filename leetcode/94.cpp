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

// Approach 1 : Morris Inorder Traversal
// Time Complexity : O(n)
// Space Complexity : O(1)

// class Solution {
//  public:
//   vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> traverse;

//     TreeNode* curr = root;
//     while (curr) {
//       if (!curr->left) {
//         traverse.push_back(curr->val);
//         curr = curr->right;
//       } else {
//         TreeNode* prev = curr->left;

//         while (prev->right && (prev->right != curr)) {
//           prev = prev->right;
//         }

//         if (!prev->right) {
//           prev->right = curr;
//           curr = curr->left;
//         } else {
//           prev->right = nullptr;
//           traverse.push_back(curr->val);
//           curr = curr->right;
//         }
//       }
//     }

//     return traverse;
//   }
// };

// Approach 2 : Recursive Inorder Traversal (DFS)
// Time Complexity : O(n)
// Space Complexity = O(h)

class Solution {
 public:
  void traverse(TreeNode* root, vector<int>& inOrder) {
    if (!root) return;

    traverse(root->left, inOrder);
    inOrder.push_back(root->val);
    traverse(root->right, inOrder);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inOrder;
    traverse(root, inOrder);
    return inOrder;
  }
};