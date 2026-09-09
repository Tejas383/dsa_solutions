#include <bits/stdc++.h>
using namespace std;

// Approach Name: Mathematical / Direct Formula Approach
// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
 public:
  int countCommas(int n) {
    if (n < 1000) return 0;

    return n - 999;
  }
};