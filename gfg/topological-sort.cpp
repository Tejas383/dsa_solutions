#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/topological-sort/1

// Approach: Kahn's Algorithm (BFS Topological Sort)
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
 public:
  vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);
    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      ans.push_back(curr);

      for (auto nbr : adj[curr]) {
        indegree[nbr]--;
        if (indegree[nbr] == 0) q.push(nbr);
      }
    }

    return ans;
  }
};