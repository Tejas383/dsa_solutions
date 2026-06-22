#include <bits/stdc++.h>
using namespace std;

// Approach Name: Prefix Sum + Remainder Frequency
// Time complexity = O(n)
// Space complexity = O(min(n, k))

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
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