#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/square-root/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int floorSqrt(int n) {
    // code here
    int low = 1;
    int high = n;
    int mid;
    int ans;

    while (low <= high) {
      mid = (low + high) / 2;

      int sq = mid * mid;

      if (sq == n) return mid;

      // if the square of mid is greater than n, search in the lower half
      if (sq > n) {
        high = mid - 1;
      } else {
        ans = mid;
        low = mid + 1;
      }
    }

    return ans;
  }
};