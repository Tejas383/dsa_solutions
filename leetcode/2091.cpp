#include <bits/stdc++.h>
using namespace std;

// Approach : Greedy approach
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size();

    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] < nums[minIndex]) minIndex = i;
      if (nums[i] > nums[maxIndex]) maxIndex = i;
    }

    cout << n << " " << minIndex << " " << maxIndex << endl;

    int a, b, c;
    a = max(minIndex, maxIndex) + 1;
    b = n - min(minIndex, maxIndex);
    c = min(minIndex, maxIndex) + n - max(minIndex, maxIndex) + 1;

    return min({a, b, c});
  }
};