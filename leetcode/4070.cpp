#include <bits/stdc++.h>
using namespace std;

// Approach: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
 public:
  int minRotations(string s) {
    int ans = 0;
    int curr = 0;

    for (const auto& c : s) {
      int d = c - '0';

      int r = abs(curr - d);
      ans += min(r, 10 - r);

      curr = d;
    }

    return ans;
  }
};