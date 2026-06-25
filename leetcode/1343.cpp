#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
      int j = i - k + 1;

      sum += arr[i];

      if (j < 0) continue;

      int avg = sum / k;

      if (avg >= threshold) count++;

      sum -= arr[j];
    }

    return count;
  }
};