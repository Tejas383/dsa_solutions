#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
// Approach Name: Prefix Sum + Remainder Frequency
// Time complexity = O(n)
// Space complexity = O(min(n, k))

class Solution {
 public:
  // Function to count the number of subarrays with a sum that is divisible by K
  int subCount(vector<int>& nums, int k) {
    // Your code goes here
    unordered_map<int, int> m;

    int rem = 0;

    int ans = 0;

    for (auto num : nums) {
      rem += num;
      rem %= k;

      if (rem < 0) rem += k;

      if (rem == 0) ans++;

      if (m.count(rem)) ans += m[rem];

      m[rem]++;
    }

    return ans;
  }
};
