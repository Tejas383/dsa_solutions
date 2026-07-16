#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Approach Name: Recursive BFS
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution {
 public:
  vector<int> bfs(vector<vector<int>>& adj) {
    // code here
    int n = adj.size();
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vector<bool> vis(n, false);
    vis[0] = true;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      ans.push_back(curr);

      for (auto nbr : adj[curr]) {
        if (!vis[nbr]) {
          vis[nbr] = true;
          q.push(nbr);
        }
      }
    }

    return ans;
  }
};