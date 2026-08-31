#include <bits/stdc++.h>
using namespace std;

// Approach : Unordered Set
// Time Complexity : O(max(n, k))
// Space Complexity : O(n)

class Solution {
 public:
  int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int> s(nums.begin(), nums.end());

    int i = k;
    while (s.find(i) != s.end()) i += k;

    return i;
  }
};