#include <bits/stdc++.h>
using namespace std;

// Approach Name: BFS from Every Node (Brute Force)
// Time complexity = O(n ^ 3)
// Space complexity = O(n)

class Solution {
  vector<vector<int>> adj;
  vector<int> ans;

  int bfs(int k, int node) {
    queue<int> q;
    vector<bool> vis(adj.size(), false);

    q.push(node);
    vis[node] = true;

    while (!q.empty() && k > 0) {
      int s = q.size();
      while (s--) {
        int curr = q.front();
        q.pop();

        for (const auto& nbr : adj[curr]) {
          if (!vis[nbr]) {
            q.push(nbr);
            vis[nbr] = true;
          }
        }
      }
      k--;
    }

    return q.size();
  }

 public:
  vector<int> countOfPairs(int n, int x, int y) {
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
      adj[i].push_back(i + 1);
      adj[i + 1].push_back(i);
    }

    adj[x].push_back(y);
    adj[y].push_back(x);

    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      int c = 0;

      for (int j = 1; j <= n; j++) {
        c += bfs(i, j);
      }
      ans[i] = c;
    }

    ans.erase(ans.begin());

    return ans;
  }
};