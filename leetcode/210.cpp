#include <bits/stdc++.h>
using namespace std;

// Approach Name: Kahn's Algorithm (BFS Topological Sort)
// Time complexity = O(v + e)
// Space complexity = O(v + e)

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (const auto& req : prerequisites) {
      // notice that the edge goes from b to a,
      // since to complete a, b is required
      adj[req[1]].push_back(req[0]);
      indegree[req[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      ans.push_back(curr);

      for (const auto& nbr : adj[curr]) {
        if (--indegree[nbr] == 0) q.push(nbr);
      }
    }

    if (ans.size() == numCourses) return ans;
    return {};
  }
};