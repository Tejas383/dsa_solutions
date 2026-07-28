#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Approach Name: Floyd-Warshall Algorithm
// Time Complexity: O(V^3)
// Space Complexity: O(1)

class Solution {
 public:
  void floydWarshall(vector<vector<int>>& dist) {
    // Code here
    int n = dist.size();

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] != 100000000 && dist[k][j] != 100000000)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
};