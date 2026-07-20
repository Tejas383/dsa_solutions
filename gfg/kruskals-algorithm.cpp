#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

// Approach name: Disjoint Set Union (Union-Find)
// Time Complexity: O(E log E + E · α(V))
// Space Complexity: O(V)

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

  static bool comparator(vector<int>& a, vector<int>& b) { 
    return a[2] < b[2]; 
  }

 public:
  int kruskalsMST(int V, vector<vector<int>>& edges) {
    // code here
    sort(edges.begin(), edges.end(), comparator);
    parent.resize(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int weight = 0;
    int taken = 0;
    for (const auto& edge : edges) {
      if (taken == V - 1) break;

      if (find(edge[0]) != find(edge[1])) {
        makeUnion(edge[0], edge[1]);
        weight += edge[2];
        taken++;
      }
    }

    return weight;
  }
};