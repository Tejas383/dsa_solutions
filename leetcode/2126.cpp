#include <bits/stdc++.h>
using namespace std;

// Approach Name: Greedy + Sorting
// Time ciomplexity = O(n * log n)
// Space complexity = O(n)

class Solution {
 public:
  bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    long long s = mass;
    sort(asteroids.begin(), asteroids.end());
    for (auto m : asteroids) {
      if (s < m) return false;
      s += m;
    }

    return true;
  }
};