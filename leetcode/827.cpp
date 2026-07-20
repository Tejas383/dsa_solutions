#include <bits/stdc++.h>
using namespace std;

// Approach Name: Disjoint Set Union (Union-Find) + Component Size Tracking
// Time complexity = O(n ^ 2)
// Space complexity = O(n ^ 2)

class Solution {
  vector<int> parent;
  vector<int> size;

  void makeUnion(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;

    if (size[parentA] > size[parentB]) {
      parent[parentB] = parentA;
      size[parentA] += size[parentB];
    } else {
      parent[parentA] = parentB;
      size[parentB] += size[parentA];
    }
  }

  int find(int a) {
    if (parent[a] == a) return a;

    return parent[a] = find(parent[a]);
  }

 public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    size.resize(n * n, 1);
    parent.resize(n * n);
    for (int i = 0; i < n * n; i++) {
      parent[i] = i;
    }

    vector<pair<int, int>> zeros;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          zeros.push_back({i, j});
          continue;
        }

        int node = n * i + j;

        for (int k = 0; k < 4; k++) {
          int I = i + dx[k];
          int J = j + dy[k];

          if (I >= 0 && I < n && J >= 0 && J < n && grid[I][J] == 1) {
            int nbr = n * I + J;

            makeUnion(node, nbr);
          }
        }
      }
    }

    if (zeros.empty()) {
      int ans = size[find(0)];
      return ans;
    }

    int sz = 0;

    for (const auto& p : zeros) {
      int i = p.first;
      int j = p.second;

      int node = n * i + j;
      int s = 0;

      unordered_set<int> st;

      for (int k = 0; k < 4; k++) {
        int I = i + dx[k];
        int J = j + dy[k];

        if (I >= 0 && I < n && J >= 0 && J < n && grid[I][J] == 1) {
          int nbr = n * I + J;

          int ulpar = find(nbr);
          if (!st.contains(ulpar)) {
            st.insert(ulpar);
            s += size[ulpar];
          }
        }
      }

      sz = max(sz, s + 1);
    }

    return sz;
  }
};