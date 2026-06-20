#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer
// Time complexity = O(n logn)
// Space complexity = O(1)

class Solution {
 public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = INT_MIN;
    for (auto num : nums) high = max(high, num);

    cout << low << " " << high << endl;

    int ans;

    while (low <= high) {
      int mid = (low + high) / 2;

      long long sum = 0;
      for (auto num : nums) {
        sum += ceil((double)num / mid);
      }

      if (sum <= threshold) {
        high = mid - 1;
      } else {
        ans = mid;
        low = mid + 1;
      }
    }

    return low;
  }
};