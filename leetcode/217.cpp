#include <bits/stdc++.h>
using namespace std;

// Approach Name: Hash-set (Unordered)
// Time ciomplexity = O(n), O(n^2) in worst case
// Space complexity = O(n)

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;

    for (auto num : nums) {
      if (s.find(num) == s.end())
        s.insert(num);
      else
        return true;
    }

    return false;
  }
};