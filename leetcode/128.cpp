#include <bits/stdc++.h>
using namespace std;

// Approach Name: Hash Set + Sequence Start Detection
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    int maxLen = 0;

    for (int num : s) {
      // start only if num is the beginning of a sequence
      if (s.find(num - 1) == s.end()) {
        int curr = num;
        int len = 1;

        while (s.find(curr + 1) != s.end()) {
          curr++;
          len++;
        }

        maxLen = max(maxLen, len);
      }
    }

    return maxLen;
  }
};
