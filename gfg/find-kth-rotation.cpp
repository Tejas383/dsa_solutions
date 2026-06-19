#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/rotation4723/1
// Approach Name: Binary Search
// Time complexity = O(log n)
// Space complexity = O(1)

// Intuition: The index of the minimum element is the number of rotations

class Solution {
 public:
  int findKRotation(vector<int>& arr) {
    // Code Here
    int low = 0;
    int high = arr.size() - 1;
    int mid;

    while (low < high) {
      mid = (low + high) / 2;

      if (arr[mid] > arr[high])
        low = mid + 1;
      else
        high = mid;
    }

    return low;
  }
};
