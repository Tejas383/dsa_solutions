#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Partition
// Time ciomplexity = O(min(n1, n2))
// Space complexity = O(1)

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) 
      swap(nums1, nums2);
    // smaller array is nums1

    int n1 = nums1.size();
    int n2 = nums2.size();
    cout << n1 << " " << n2 << endl;
    int n = n1 + n2;
    int low = 0;
    int high = n1;
    // indices

    double l1, l2, r1, r2;
    // elements

    while (low <= high) {
      int mid1 = (low + high) / 2;
      int mid2 = (n / 2) - mid1;

      if (mid1 == 0)
        l1 = INT_MIN;
      else
        l1 = nums1[mid1 - 1];

      if (mid1 == n1)
        r1 = INT_MAX;
      else
        r1 = nums1[mid1];

      if (mid2 == 0)
        l2 = INT_MIN;
      else
        l2 = nums2[mid2 - 1];

      if (mid2 == n2)
        r2 = INT_MAX;
      else
        r2 = nums2[mid2];

      if (l1 > r2)
        high = mid1 - 1;
      else if (l2 > r1)
        low = mid1 + 1;
      else
        break;
    }

    if (n % 2 == 0) 
      return (max(l1, l2) + min(r1, r2)) / 2;
    return min(r1, r2);
  }
};