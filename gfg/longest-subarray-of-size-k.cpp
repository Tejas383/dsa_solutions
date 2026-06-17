#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// Approach Name: Prefix Sum + First Occurrence Hashing
// Time ciomplexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int longestSubarray(vector<int>& arr, int k) {
    // code here
    int sum = 0;
    int len = 0;

    unordered_map<int, int> idx;

    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];

      if (sum == k) len = max(len, i + 1);

      int val = sum - k;
      if (idx.count(val)) len = max(len, i - idx[val]);

      if (!idx.count(sum)) idx[sum] = i;
    }

    return len;
  }
};