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

// Approach 1 : Morris Traversal
// Time Complexity : O(n)
// Space Complexity : O(1)

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> traverse;
//         if (!root)
//             return traverse;

//         TreeNode* node = root;
//         stack<TreeNode*> st;
//         st.push(node);

//         unordered_map<TreeNode*, int> visited;
//         while (!st.empty()) {
//             node = st.top();
//             if (!visited.count(node)) {
//                 visited[node]++;
//                 if (node->right)
//                     st.push(node->right);
//                 if (node->left)
//                     st.push(node->left);
//             } else {
//                 traverse.push_back(node->val);
//                 st.pop();
//             }
//         }

//         return traverse;
//     }
// };

// Approach 2 : Recursive Traversal (DFS)
// Time Complexity : O(n)
// Space Complexity = O(h)

class Solution {
 public:
  void traverse(TreeNode* root, vector<int>& postOrder) {
    if (!root) return;

    traverse(root->left, postOrder);
    traverse(root->right, postOrder);
    postOrder.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postOrder;
    traverse(root, postOrder);
    return postOrder;
  }
};