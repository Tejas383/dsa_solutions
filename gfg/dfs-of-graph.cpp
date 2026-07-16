#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Approach Name: Recursive DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
  int n;
  vector<bool> vis;
  vector<int> ans;

  void dfs(int curr, vector<vector<int>>& adj) {
    ans.push_back(curr);
    for (auto nbr : adj[curr]) {
      if (!vis[nbr]) {
        vis[nbr] = true;
        dfs(nbr, adj);
      }
    }
  }

 public:
  vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    n = adj.size();
    vis.resize(n, false);
    vis[0] = true;
    dfs(0, adj);

    return ans;
  }
};