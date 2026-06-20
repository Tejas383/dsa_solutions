#include <bits/stdc++.h>
using namespace std;

// Approach 1: Two-pass constraint relaxation
// Time complexity = O(n)
// Space complexity = O(n), causing MLE

// Approach 2: Greedy Constraint Propagation + Interval Peak Calculation
// Time complexity = O(m log m)
// Space complexity = O(1)

class Solution {
 public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    // add the 1st and last index along with the respective height restriction
    restrictions.push_back({1, 0});
    restrictions.push_back({n, n - 1});

    // Sort restrictions on the basis of index
    sort(restrictions.begin(), restrictions.end());

    // since the maxheight of the 1st building is 0,
    // therefore, the max height of the ith building will be i - 1
    for (int i = 0; i < restrictions.size(); i++)
      restrictions[i][1] = min(restrictions[i][1], restrictions[i][0] - 1);

    // Left-to-Right Constraint Propagation:
    // since 2 buildings are 'd' distance apart,
    // their height difference cannot exceed more than d
    // so , the height of this building = height of prev building + d
    for (int i = 1; i < restrictions.size(); i++) {
      int d = restrictions[i][0] - restrictions[i - 1][0];
      restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + d);
    }

    // Right-to-Left Constraint Propagation:
    // applying the same logic in the opposite direction
    for (int i = restrictions.size() - 2; i > 0; i--) {
      int d = restrictions[i + 1][0] - restrictions[i][0];
      restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + d);
    }

    int ans = 0;
    for (int i = 1; i < restrictions.size(); i++) {
      // maximum height difference
      int d = restrictions[i][0] - restrictions[i - 1][0];

      int h1 = restrictions[i][1];
      int h2 = restrictions[i - 1][1];

      // maximum height between this and prev building (both included)
      // maximum of this and previous height
      //                +
      // abs(h1 - h2) -> difference between the heights
      // split the difference between both the sides to get the peak
      int a = max(h1, h2) + (d - abs(h1 - h2)) / 2;
      ans = max(ans, a);
    }

    return ans;
  }
};