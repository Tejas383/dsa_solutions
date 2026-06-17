#include <bits/stdc++.h>
using namespace std;

// Approach Name: Prefix Sum + Hash Map Frequency Counting
// Time ciomplexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> idx;

    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      if (sum == k) cnt++;

      int val = sum - k;
      if (idx.count(val)) cnt += idx[val];

      idx[sum]++;
    }

    return cnt;
  }
};