#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

// Approach Name: Union-Find with Path Compression
// Time Complexity: O(α)
// Space Complexity: On)

class Solution {
  // we have to merge x,y
  void makeUnion(vector<int>& parent, int x, int y) {
    // finding ultimate parents of x and y
    int parentX = find(parent, x);
    int parentY = find(parent, y);

    if (parentX == parentY) {
      return;
    }

    parent[parentX] = parentY;
  }

  int find(vector<int>& parent, int i) {
    if (parent[i] == i) return i;

    // path compression
    parent[i] = find(parent, parent[i]);
    return find(parent, parent[i]);
  }

 public:
  vector<int> DSU(int n, vector<vector<int>>& queries) {
    // code here
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }

    vector<int> ans;
    for (auto query : queries) {
      if (query[0] == 2) {
        ans.push_back(find(parent, query[1]));
      } else if (query[0] == 1) {
        makeUnion(parent, query[1], query[2]);
      }
    }

    return ans;
  }
};