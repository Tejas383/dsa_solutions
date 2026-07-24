#include <bits/stdc++.h>
using namespace std;

// Approach name: Modified Dijkstra's Algorithm (Min Heap + State = Node + Number of Stops) 
// Time Complexity: O(KE log(VK)) 
// Space Complexity: O(V + E + KV)

class Solution {
  vector<vector<vector<int>>> adj;
  vector<vector<int>> dist;

 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, 
                        int src, int dst, int k) {
    adj.resize(n);
    for (const auto& flight : flights)
      adj[flight[0]].push_back({flight[1], flight[2]});

    dist.resize(k + 2, vector<int>(n, INT_MAX));
    // dist = {node number, distance of node}

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // pq = {current cost, end node, steps left}
    pq.push({0, src, 0});
    dist[0][src] = 0;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      int cost = curr[0];
      int node = curr[1];
      int l = curr[2];

      if (node == dst) return cost;

      if (l > k) continue;

      for (const auto& nbr : adj[node]) {
        int n = nbr[0];
        int c = nbr[1];

        if (dist[l][node] + c < dist[l + 1][n]) {
          dist[l + 1][n] = dist[l][node] + c;
          pq.push({dist[l + 1][n], n, l + 1});
        }
      }
    }

    return -1;
  }
};