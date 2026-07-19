#include <bits/stdc++.h>
using namespace std;

// Approach Name: Level Order Traversal
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

class Codec {
 public:
  // Encodes a binary tree into a string using Level Order Traversal.
  // Null nodes are represented using 'x'.
  string serialize(TreeNode* root) {
    string ser = "";

    if (!root) return ser;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();

      // Store a marker for null nodes.
      if (!curr) {
        ser += "x.";
      } else {
        // Store the current node's value.
        ser += to_string(curr->val);
        ser += ".";

        // Push both children, including nullptr,
        // so the exact tree structure is preserved.
        q.push(curr->left);
        q.push(curr->right);
      }
    }

    return ser;
  }

  // Decodes the serialized string back into the original tree.
  TreeNode* deserialize(string data) {
    if (data == "") return nullptr;

    // Split the serialized string using '.' as the delimiter.
    vector<string> vec;
    stringstream str(data);
    string token;

    while (getline(str, token, '.')) vec.push_back(token);

    // First value is always the root.
    int i = 0;
    TreeNode* root = new TreeNode(stoi(vec[0]));

    queue<TreeNode*> q;
    q.push(root);
    i++;

    // Reconstruct the tree level by level.
    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();

      // Create the left child if it is not null.
      if (i < vec.size()) {
        if (vec[i] != "x") {
          TreeNode* left = new TreeNode(stoi(vec[i]));
          curr->left = left;
          q.push(left);
        }
        i++;
      }

      // Create the right child if it is not null.
      if (i < vec.size()) {
        if (vec[i] != "x") {
          TreeNode* right = new TreeNode(stoi(vec[i]));
          curr->right = right;
          q.push(right);
        }
        i++;
      }
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));