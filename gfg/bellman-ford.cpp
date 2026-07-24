#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Approach name: Bellman Ford
// Time Complexity: O(E * V)
// Space Complexity: O(V + E)

class Solution {
 public:
  vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dist(V, 100000000);
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
      for (const auto& edge : edges) {
        int start = edge[0];
        int end = edge[1];
        int weight = edge[2];

        if (dist[start] < 100000000 && dist[start] + weight < dist[end]) {
          // -ve cycle exists
          if (i == V - 1) return {-1};
          dist[end] = dist[start] + weight;
        }
      }
    }

    return dist;
  }
};
