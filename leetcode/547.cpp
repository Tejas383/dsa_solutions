#include <bits/stdc++.h>
using namespace std;

// Approach Name: Union-Find with Path Compression
// Time complexity = O(n ^ 2)
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
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1) makeUnion(i, j);
      }
    }

    int provinces = 0;
    for (int i = 0; i < n; i++) {
      if (parent[i] == i) provinces++;
    }

    return provinces;
  }
};