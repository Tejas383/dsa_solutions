#include <bits/stdc++.h>
using namespace std;

// Approach Name: One-Pass Greedy / Minimum Price Tracking
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int ans = INT_MIN;

    for (const auto& currPrice : prices) {
      minPrice = min(minPrice, currPrice);
      ans = max(ans, currPrice - minPrice);
    }

    return ans;
  }
};