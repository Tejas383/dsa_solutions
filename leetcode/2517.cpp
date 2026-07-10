#include <bits/stdc++.h>
using namespace std;

// Approach Name: Binary Search on Answer
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    int n = price.size();
    sort(price.begin(), price.end());

    int low = 0;
    int high = price[n - 1] - price[0];
    int mid;
    int ans;

    while (low <= high) {
      mid = (low + high) / 2;

      int cnt = 1;
      int curr = price[0];
      for (int i = 1; i < n; i++) {
        int diff = price[i] - curr;
        if (diff >= mid) {
          cnt++;
          curr = price[i];
        }
      }

      if (cnt < k)
        high = mid - 1;
      else {
        ans = mid;
        low = mid + 1;
      }
    }

    return ans;
  }
};