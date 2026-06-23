#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer
// Time complexity = O(n log(sum of weights))
// Space complexity = O(1)

class Solution {
 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int low = INT_MIN;
    int high = 0;
    for (auto weight : weights) {
      low = max(low, weight);
      high += weight;
    }

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int sum = 0;
      int d = 1;
      for (auto weight : weights) {
        sum += weight;

        if (sum > mid) {
          sum = weight;
          d++;
        }
      }

      if (d <= days) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};