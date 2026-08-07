#include <bits/stdc++.h>
using namespace std;

// Approach : Recursion + Memoization (Top-Down DP + Binary Search)
// Time complexity : O((n * (n + m)) * log m)
// Space complexity : O(n * (n + m))

class Solution {
  map<pair<int, int>, int> dp;
  // dp = {{index, prev}, number of operations made}

  int helper(int prev, int i, auto& arr1, auto& arr2) {
    if (dp.count({i, prev})) return dp[{i, prev}];

    if (i == arr1.size()) return dp[{i, prev}] = 0;

    int cont = 1e9 + 1;
    ;
    if (arr1[i] > prev) cont = helper(arr1[i], i + 1, arr1, arr2);

    // swap
    int sw;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if (it == arr2.end())
      sw = 1e9 + 1;
    else {
      int idx = it - arr2.begin();
      // int idx = *it;

      sw = 1 + helper(arr2[idx], i + 1, arr1, arr2);
    }

    return dp[{i, prev}] = min(cont, sw);
  }

 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    dp = {};

    sort(arr2.begin(), arr2.end());

    int ans = helper(-1, 0, arr1, arr2);
    return ans > 1e9 ? -1 : ans;
  }
};