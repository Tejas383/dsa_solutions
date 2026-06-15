#include <bits/stdc++.h>
using namespace std;

// Approach Name: Reverse Traversal
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxPrice = -1;
    int ans = 0;

    for (int i = prices.size() - 1; i >= 0; i--) {
      int price = prices[i];

      int value = maxPrice - price;

      if (price > maxPrice) {
        maxPrice = price;
      }

      ans = max(ans, value);
    }

    return ans;
  }
};