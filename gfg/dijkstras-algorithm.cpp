#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Approach name: Greedy + Min Heap / Priority Queue + Adjacency List
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)

class Solution {
 public:
  vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<vector<vector<int>>> adj(V);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
      adj[edge[1]].push_back({edge[0], edge[2]});
    }
    // adj = {start, end, dist}

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    // pq = {total dist, end}

    pq.push({0, src});
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      int dis = curr.first;
      int node = curr.second;

      if (dis > dist[node]) continue;

      for (const auto& nbr : adj[node]) {
        // nbr = vec {node, weight}
        int n = nbr[0];
        int w = nbr[1];

        if (dist[node] + w < dist[n]) {
          dist[n] = dist[node] + w;
          pq.push({dist[n], n});
        }
      }
    }

    return dist;
  }
};