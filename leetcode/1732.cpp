#include <bits/stdc++.h>
using namespace std;

// Approach Name: Prefix Sum
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int alt = 0;
    int maxAlt = 0;

    for (auto g : gain) {
      alt += g;
      maxAlt = max(alt, maxAlt);
    }

    return maxAlt;
  }
};