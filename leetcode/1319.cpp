#include <bits/stdc++.h>
using namespace std;

// Approach Name: Union-Find with Path Compression
// Time complexity = O(n + m * α)
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
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;

    // TC = O(n)
    parent.resize(n);
    for (int i = 0; i < n; i++) 
      parent[i] = i;

    // TC = O(m * α)
    for (auto conn : connections) 
      makeUnion(conn[0], conn[1]);

    // count of unconnected components
    // only those components are not connected whose parent is equal to itself
    // TC = O(n)
    int count = 0;
    for (int i = 0; i < n; i++)
      if (parent[i] == i) count++;

    return count - 1;
  }
};