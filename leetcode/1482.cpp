#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer
// Time complexity = O(n logn)
// Space complexity = O(1)

class Solution {
 public:
  bool possible(vector<int>& arr, int day, int bouquets, int flowers) {
    int consecutive = 0;  // number of consecutive flowers
    int made = 0;         // number of bouquets made

    for (auto a : arr) {
      if (a <= day) {
        consecutive++;

        if (consecutive == flowers) {
          made++;
          consecutive = 0;

          if (made == bouquets) return true;
        }
      } else
        consecutive = 0;
    }

    return false;
  }

  int minDays(vector<int>& bloomDay, int m, int k) {
    // m -> number of bouquets to make
    // k -> number of flowers in each bouquet

    if ((long long)m * (long long)k > bloomDay.size()) return -1;

    int low = INT_MAX;
    int high = INT_MIN;
    int mid;
    int ans;

    for (auto day : bloomDay) {
      low = min(low, day);
      high = max(high, day);
    }

    while (low <= high) {
      mid = (low + high) / 2;

      if (possible(bloomDay, mid, m, k)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};