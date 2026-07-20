#include <bits/stdc++.h>
using namespace std;

// Approach Name: Disjoint Set Union (DSU) with Path Compression
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
  vector<int> parent;

  void makeUnion(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;

    parent[parentA] = parentB;
  }

  int find(int a) {
    if (parent[a] == a) return a;

    return parent[a] = find(parent[a]);
  }

 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }

    for (const auto& edge : edges) {
      if (find(edge[0]) == find(edge[1])) return edge;
      makeUnion(edge[0], edge[1]);
    }

    return {};
  }
};