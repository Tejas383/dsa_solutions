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

// Approach Name: Single-Pass Recursive DFS (Height + Distance Propagation)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  int ans = 0;

  int dfs(Node* root, int target) {
    if (!root) return 0;

    int left = dfs(root->left, target);
    int right = dfs(root->right, target);

    if (root->data == target) {
      ans = max(left, right);
      return -1;
    }

    if (left < 0) {
      ans = max(ans, right - left);
      return left - 1;
    }

    if (right < 0) {
      ans = max(ans, left - right);
      return right - 1;
    }

    return max(left, right) + 1;
  }

 public:
  int minTime(Node* root, int target) {
    // code here
    if (!root) return 0;

    dfs(root, target);
    return ans;
  }
};