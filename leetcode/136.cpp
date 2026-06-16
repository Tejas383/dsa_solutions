#include <bits/stdc++.h>
using namespace std;

// Approach Name: Bitwise XOR
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int a = 0;

    for (auto num : nums) {
      a ^= num;
    }

    return a;
  }
};