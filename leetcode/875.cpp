#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer
// Time complexity = O(n logn)
// Space complexity = O(1)

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = 0;
    for (auto pile : piles) high = max(high, pile);
    int ans;

    while (low <= high) {
      int mid = (low + high) / 2;

      long long hours = 0;
      for (auto pile : piles) {
        hours += ceil(double(pile) / mid);
      }

      if (hours <= h) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};