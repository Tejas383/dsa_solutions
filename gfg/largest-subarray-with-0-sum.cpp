#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Approach Name: Prefix Sum + Hash Map
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int maxLength(vector<int>& arr) {
    // code here
    int len = 0;
    int maxLen = 0;

    unordered_map<int, int> mp;

    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];

      if (sum == 0) {
        len = i + 1;
      } else {
        if (mp.count(sum))
          len = max(len, i - mp[sum]);
        else
          mp[sum] = i;
      }
    }

    return len;
  }
};