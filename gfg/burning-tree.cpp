#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

// Approach Name: Breadth-First Search (BFS) with Parent Mapping
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  int minTime(Node* root, int target) {
    // code here
    unordered_map<Node*, Node*> parent;

    queue<Node*> q;
    q.push(root);

    Node* targetNode;

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      if (curr->data == target) targetNode = curr;

      if (curr->left) {
        parent[curr->left] = curr;
        q.push(curr->left);
      }

      if (curr->right) {
        parent[curr->right] = curr;
        q.push(curr->right);
      }
    }

    q.push(targetNode);
    unordered_set<Node*> vis;
    vis.insert(targetNode);

    int time = 0;

    while (!q.empty()) {
      int s = q.size();

      while (s--) {
        Node* curr = q.front();
        q.pop();

        if (parent.count(curr) && !vis.count(parent[curr])) {
          q.push(parent[curr]);
          vis.insert(parent[curr]);
        }

        if (curr->left && !vis.count(curr->left)) {
          q.push(curr->left);
          vis.insert(curr->left);
        }

        if (curr->right && !vis.count(curr->right)) {
          q.push(curr->right);
          vis.insert(curr->right);
        }
      }

      time++;
    }

    return --time;
  }
};