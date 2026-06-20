#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int nthRoot(int n, int m) {
    // Code here
    if (m == 0) return 0;

    int low = 1;
    int high = m;

    while (low <= high) {
      int mid = (low + high) / 2;

      int x = pow(mid, n);

      if (x == m) return mid;

      if (x < m)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return -1;
  }
};