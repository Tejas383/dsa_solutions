#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int firstPos(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
      mid = (low + high) / 2;

      if (target <= arr[mid]) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

  int lastPos(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
      mid = (low + high) / 2;

      if (target < arr[mid]) {
        high = mid - 1;
      } else {
        ans = mid;
        low = mid + 1;
      }
    }

    return ans;
  }

  int countFreq(vector<int>& arr, int target) {
    // code here
    int ans = lastPos(arr, target) - firstPos(arr, target);

    if (ans >= arr.size()) return 0;
    return ans + 1;
  }
};
