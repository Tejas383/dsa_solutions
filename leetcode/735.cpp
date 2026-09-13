#include <bits/stdc++.h>
using namespace std;

// Approach: Deque Simulation
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    deque<int> dq;

    for (int i = 0; i < asteroids.size(); i++) {
      if (dq.empty()) {
        dq.push_back(asteroids[i]);
        continue;
      }

      if (asteroids[i] < 0) {
        while (!dq.empty() && dq.back() > 0 && dq.back() < -asteroids[i])
          dq.pop_back();

        if (!dq.empty() && dq.back() == -asteroids[i]) {
          dq.pop_back();
          continue;
        }

        if (!dq.empty() && dq.back() > -asteroids[i]) continue;
      }

      dq.push_back(asteroids[i]);
    }

    vector<int> ans(dq.begin(), dq.end());
    return ans;
  }
};