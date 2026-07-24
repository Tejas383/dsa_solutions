#include <bits/stdc++.h>
using namespace std;

// Approach name: Modified Dijkstra's Algorithm (Greedy + Max Heap for Maximum Probability Path) 
// Time Complexity: O(E log V) 
// Space Complexity: O(V + E)

class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start_node,
                        int end_node) {
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
      adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    priority_queue<pair<double, int>> pq;
    // pq = {max probability to reach current node, current node}
    pq.push({1, start_node});
    vector<double> prob(n, 0);
    prob[start_node] = 1;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      double pr = curr.first;
      int node = curr.second;

      for (const auto& nbr : adj[node]) {
        int n = nbr.first;
        double p = nbr.second;

        if (pr * p > prob[n]) {
          prob[n] = pr * p;
          pq.push({prob[n], n});
        }
      }
    }

    return prob[end_node];
  }
};