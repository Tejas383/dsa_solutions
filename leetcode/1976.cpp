#include <bits/stdc++.h>
using namespace std;

// Approach name: Dijkstra's Algorithm + Ways Tracking (Path Counting)
// Time Complexity: O((V + E) log V)
// Space Complexity: O(V + E)

class Solution {
  vector<vector<pair<int, int>>> adj;
  vector<long long> dist;
  vector<long long> ways;
  int MOD = 1000000007;

  void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    pq.push({0, 0});
    // pq = {current distance, end node}
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      auto dis = curr.first;
      auto node = curr.second;

      if (dis > dist[node]) continue;

      for (auto nbr : adj[node]) {
        // nbr = {to node, weight}
        int n = nbr.first;
        int w = nbr.second;

        long long d = 1LL * dist[node] + w;
        if (d < dist[n]) {
          dist[n] = d;
          pq.push({dist[n], n});
          // if distance from the current path < minimum distance
          ways[n] = ways[node];
        } else if (d == dist[n]) {
          // if distance from the current path == minimum distance
          ways[n] = (ways[n] + ways[node]) % MOD;
        }
      }
    }
  }

 public:
  int countPaths(int n, vector<vector<int>>& roads) {
    dist.resize(n, LLONG_MAX);
    ways.resize(n, 0);
    adj.resize(n);

    for (const auto& road : roads) {
      adj[road[0]].push_back({road[1], road[2]});
      adj[road[1]].push_back({road[0], road[2]});
    }

    dijkstra();

    return ways[n - 1] % MOD;
  }
};