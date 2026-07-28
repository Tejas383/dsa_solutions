#include <bits/stdc++.h>
using namespace std;

// Approach name: Binary Search on Answer + Sliding Window Maximum (using Monotonic Deque) 
// Time Complexity: O(n log n) 
// Space Complexity: O(n)

class Solution {
 public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    int n = chargeTimes.size();
    int low = 0;
    int high = n;
    int mid;

    while (low <= high) {
      mid = (low + high) / 2;

      int k = mid;

      deque<int> dq;
      // to store the maximum charge time from chargeTimes
      long long sum = 0;
      int maxTime = INT_MAX;
      for (int i = 0; i < n; i++) {
        int j = i - k + 1;
        sum += 1LL * runningCosts[i];

        if (j > 0) {
          sum -= 1LL * runningCosts[j - 1];
        }

        if (!dq.empty() && j > dq.front()) dq.pop_front();

        while (!dq.empty() && chargeTimes[i] > chargeTimes[dq.back()])
          dq.pop_back();

        dq.push_back(i);

        if (j >= 0) {
          maxTime = chargeTimes[dq.front()];
          if (maxTime + sum * k <= budget) break;
        }
      }

      if (maxTime + sum * k > budget)
        high = mid - 1;
      else
        low = mid + 1;
    }

    return high;
  }
};