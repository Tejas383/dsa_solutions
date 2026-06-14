#include <bits/stdc++.h>
using namespace std;

// Approach name: Reverse Greedy
// Time Complexity: O(log target)
// Space Complexity = O(1)

class Solution {
 public:
  int brokenCalc(int startValue, int target) {
    int steps = 0;

    while (target != startValue) {
      if (target > startValue && target % 2 == 0)
        target /= 2;
      else
        target++;

      steps++;
    }

    return steps;
  }
};