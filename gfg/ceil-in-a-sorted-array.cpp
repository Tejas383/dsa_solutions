#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int findCeil(vector<int>& arr, int x) {
    // code here
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    int ans = -1;

    while (low <= high) {
      mid = (low + high) / 2;

      if (arr[mid] < x) {
        low = mid + 1;
      } else {
        ans = mid;
        high = mid - 1;
      }
    }

    return ans;
  }
};