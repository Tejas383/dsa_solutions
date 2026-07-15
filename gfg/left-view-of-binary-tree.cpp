#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Approach Name: Breadth-First Search (BFS) / Level Order Traversal using Queue
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> leftView(Node* root) {
    // code here
    if (!root) return vector<int>();

    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int s = q.size();
      int value = q.front()->data;
      ans.push_back(value);

      while (s--) {
        Node* curr = q.front();
        q.pop();

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }

    return ans;
  }
};