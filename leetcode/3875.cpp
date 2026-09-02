#include <bits/stdc++.h>
using namespace std;

// Approach Name: Parity Observation / Mathematical Insight
// Time Complexity : O(1)
// Space Complexity : O(1)

// let's create nums2 with EVEN parity
// in this case , if the number in nums1 is even, we take it, and if a number is
// odd, we subtract if from any other odd number in nums1 this won't be possible
// if nums1 = [1, 2, 4, 6, 8] but, we can create nums2 with ODD parity instead
// i = 1 : nums1[i] - nums2[j], where j != i : 2 - 1 = 1 = odd
// similarly, for i = 2 onwards

// let nums1 = [2,3,5,7,9]
// ODD parity:
// we cannot get anything for i = 0,
// but creating nums of EVEN parity is possible,
// therefore the answer will be true ALWAYS

class Solution {
 public:
  bool uniformArray(vector<int>& nums1) { 
    return true; 
  }
};