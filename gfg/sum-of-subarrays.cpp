#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1
// Approach Name: Contribution Technique
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int subarraySum(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      ans += arr[i] * (i + 1) * (n - i);
    }

    return ans;
  }
};