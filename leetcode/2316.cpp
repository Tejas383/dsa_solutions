#include <bits/stdc++.h>
using namespace std;

// Approach Name: Disjoint Set Union (Union-Find) with Component Size Counting
// Time complexity = O((n + e) * α)
// Space complexity = O(n)

class Solution {
  vector<int> parent;
  vector<int> size;

  void makeUnion(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;

    size[parentB] += size[parentA];
    parent[parentA] = parentB;
  }

  int find(int a) {
    if (parent[a] == a) return a;

    return parent[a] = find(parent[a]);
  }

 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    size.resize(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }

    for (auto edge : edges) {
      makeUnion(edge[0], edge[1]);
    }

    long long ans = 0;
    int rem = n;
    // number of nodes in all unprocessed components
    for (int i = 0; i < n; i++) {
      if (parent[i] == i) {
        rem -= size[i];
        ans += (long long)size[i] * (long long)rem;
        // Current component has size[i] nodes.
        // Every node in the current component forms an unreachable pair with
        // every remaining node.
      }
    }

    return ans;
  }
};