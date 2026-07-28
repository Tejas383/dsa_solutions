#include <bits/stdc++.h>
using namespace std;

// Approach Name: Hash Set (Count Distinct Non-Zero Elements)
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> s;

    for (const auto& num : nums) {
      if (num != 0) s.insert(num);
    }

    return s.size();
  }
};