#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/implement-upper-bound/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

class Solution {
 public:
  int upperBound(vector<int>& arr, int target) {
    // code here
    if (target > arr[arr.size() - 1]) return arr.size();

    int low = 0;
    int high = arr.size() - 1;
    int mid;

    while (low < high) {
      mid = (low + high) / 2;

      if (arr[mid] <= target)
        low = mid + 1;
      else
        high = mid;
    }

    return low;
  }
};
