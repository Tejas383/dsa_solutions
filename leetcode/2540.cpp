#include <vector>
using namespace std;

// Approach Name: Two Pointer
// Time ciomplexity = O(n + m)
// Space ciomplexity = O(1)

class Solution {
 public:
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int i, j;
    i = j = 0;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) return nums1[i];

      if (nums1[i] > nums2[j])
        j++;
      else
        i++;
    }

    return -1;
  }
};