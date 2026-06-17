#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1
// Approach Name: Kadane-like Traversal for Maximum Non-Negative Subarray
// Time complexity = O(n)
// Space complexity = O(maxLen)

class Solution {
 public:
  vector<int> findSubarray(vector<int>& arr) {
    int sum = 0;
    int maxSum = 0;

    int len = 0;
    int maxLen = 0;

    int idx = 0;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] < 0) {
        sum = 0;
        len = 0;

        continue;
      }

      sum += arr[i];
      len++;

      if (sum == maxSum) {
        if (len > maxLen) {
          idx = i - len + 1;
          maxLen = len;
        }
      } else if (sum > maxSum) {
        maxSum = sum;
        maxLen = len;
        idx = i - len + 1;
      }
    }

    vector<int> ans;
    for (int i = idx; i < idx + maxLen; i++) {
      ans.push_back(arr[i]);
    }

    if (ans.empty()) ans.push_back(-1);

    return ans;
  }
};