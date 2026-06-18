#include <bits/stdc++.h>
using namespace std;

// Approach Name: Direct Clock Angle Calculation (Formula-based)
// Time complexity = O(1)
// Space complexity = O(1)

class Solution {
 public:
  double angleClock(int hour, int minutes) {
    if (hour == 12) hour = 0;

    double clockwise = abs((30 * hour) - (5.5 * minutes));
    double anti_clockwise = 360 - clockwise;

    return min(clockwise, anti_clockwise);
  }
};