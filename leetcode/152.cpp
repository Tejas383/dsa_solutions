#include <bits/stdc++.h>
using namespace std;

// Approach Name: Prefix Product + Suffix Product Traversal
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();

    vector<int> pre(n);
    int prod = 1;
    for (int i = 0; i < n; i++) {
      prod *= nums[i];
      pre[i] = prod;

      if (prod == 0) prod = 1;
    }

    vector<int> suf(n);
    prod = 1;
    for (int i = n - 1; i >= 0; i--) {
      prod *= nums[i];
      suf[i] = prod;

      if (prod == 0) prod = 1;
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      ans = max({ans, pre[i], suf[i]});
    }

    return ans;
  }
};