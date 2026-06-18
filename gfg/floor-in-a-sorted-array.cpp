#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int findFloor(vector<int>& arr, int x) {
    // code here
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
      mid = (low + high) / 2;

      if (x >= arr[mid]) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }

    return ans;
  }
};
