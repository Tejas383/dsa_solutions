#include <bits/stdc++.h>
using namespace std;

// Approach Name: Three-Pointer Backward Merge
// Time complexity = O(m + n)
// Space complexity = O(1)

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-- + n-- - 1;

    while (m >= 0 && n >= 0) {
      if (nums1[m] > nums2[n]) {
        swap(nums1[m--], nums1[i--]);
      } else {
        nums1[i--] = nums2[n--];
      }
    }

    if (m < 0) {
      while (n >= 0) {
        nums1[i--] = nums2[n--];
      }
    }
  }
};