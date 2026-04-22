#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Approach name: Connected Components + Frequency Difference (using BFS on
// Graph) Time Complexity: (n log n + m) Space Complexity: O(n + m) 
// where, n is the size of arrays, and, m is the number of allowed swaps

// Explanation: 
// The allowed swaps form a graph where each index is a node.
// All indices in the same connected component can be freely rearranged.
// So, instead of comparing indices directly, we compare the frequency of values
// in source and target within each connected component.
// For each component, we compute frequency difference:
// +1 for source values, -1 for target values.
// Any leftover imbalance represents unmatched elements (mismatches).
// We sum up absolute differences for all components.
// Final answer is divided by 2 because each mismatch is counted twice.

class Solution {
 public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int ans = 0;

    int n = source.size();

    vector<vector<int>> adj(n);
    for (int i = 0; i < allowedSwaps.size(); i++) {
      adj[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
      adj[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
    }

    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;

      // !vis[i]
      queue<int> q;
      q.push(i);
      vis[i] = true;
      map<int, int> freqDiff;

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        freqDiff[source[node]]++;
        freqDiff[target[node]]--;

        for (int x : adj[node]) {
          if (!vis[x]) {
            q.push(x);
            vis[x] = true;
          }
        }
      }

      for (auto p : freqDiff) 
        ans += abs(p.second);
    }

    return ans / 2;
  }
};