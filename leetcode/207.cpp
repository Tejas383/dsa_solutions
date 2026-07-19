#include <bits/stdc++.h>
using namespace std;

// Approach Name: Kahn's Algorithm (BFS Topological Sort)
// Time complexity = O(v + e)
// Space complexity = O(v + e)

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (const auto& req : prerequisites) {
      adj[req[0]].push_back(req[1]);
      indegree[req[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    int completed = 0;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      completed++;
      for (auto& nbr : adj[curr]) {
        if (--indegree[nbr] == 0) q.push(nbr);
      }
    }

    return (completed == numCourses);
  }
};