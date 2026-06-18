#include <bits/stdc++.h>
using namespace std;

// Approach Name: Dynamic Programming
// (Tracking Maximum and Minimum Product Ending at Each Index)
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int minProd = 1;
    int maxProd = 1;

    int ans = 0;

    for (auto num : nums) {
      if (num < 0) swap(minProd, maxProd);

      minProd = min(num, minProd * num);
      maxProd = max(num, maxProd * num);

      ans = max(ans, maxProd);
    }

    return ans;
  }
};