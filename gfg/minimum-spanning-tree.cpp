#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Approach name: Prim's Algorithm (Priority Queue / Min Heap)
// Time Complexity: O((V + E) log V)
// Space Complexity: O(V + E)

class Solution {
 public:
  int spanningTree(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<vector<int>>> adj(V);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
      adj[edge[1]].push_back({edge[0], edge[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // pq = {dist, end}

    vector<bool> visited(V, false);
    pq.push({0, 0});
    int weight = 0;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      if (visited[curr[1]]) continue;

      weight += curr[0];

      visited[curr[1]] = true;
      for (auto& nbr : adj[curr[1]]) {
        if (!visited[nbr[0]]) pq.push({nbr[1], nbr[0]});
      }
    }

    return weight;
  }
};