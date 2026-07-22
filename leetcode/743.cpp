#include <bits/stdc++.h>
using namespace std;

// Approach Name: Dijkstra's Algorithm
// Time complexity = O(E log V)
// Space complexity = O(V + E)

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto& time : times) 
      adj[time[0]].push_back({time[1], time[2]});

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    pq.push({0, k});
    // pq = {total dist, end}

    vector<int> time(n + 1, INT_MAX);
    time[k] = 0;

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      int dist = curr.first;
      int node = curr.second;

      for (const auto& nbr : adj[node]) {
        int n = nbr.first;
        int w = nbr.second;

        if (time[node] + w < time[n]) {
          time[n] = time[node] + w;
          pq.push({time[n], n});
        }
      }
    }

    time.erase(time.begin());

    int ans = -1;
    for (const auto& t : time) {
      if (t == INT_MAX) return -1;
      ans = max(ans, t);
    }

    return ans;
  }
};