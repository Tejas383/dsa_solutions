#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window + Frequency Map + Pair Counting (Two Pointers)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    long long ans = 0;

    unordered_map<int, int> freq;
    long long cnt = 0;
    int i = 0;
    int j = 0;

    while (i < nums.size()) {
      cnt += freq[nums[i]];
      freq[nums[i]]++;

      while (cnt >= k) {
        ans += nums.size() - i;

        freq[nums[j]]--;
        cnt -= freq[nums[j]];

        j++;
      }

      i++;
    }

    return ans;
  }
};