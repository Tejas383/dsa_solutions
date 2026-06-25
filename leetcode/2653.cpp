#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window + Frequency Counting of Negative Numbers
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    int n = nums.size();

    // initialise an array of size 50 to store the frequencies of the negative
    // elements
    int arr[51] = {0};

    vector<int> ans;

    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) arr[-nums[i]]++;

      int j = i - k + 1;
      if (j < 0) continue;

      int count = 0;
      for (int l = 50; l >= 0; l--) {
        count += arr[l];
        if (count >= x) {
          ans.push_back(-l);
          break;
        }
      }
      if (count < x) ans.push_back(0);

      if (nums[j] < 0) arr[-nums[j]]--;
    }

    return ans;
  }
};