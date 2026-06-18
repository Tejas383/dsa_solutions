#include <algorithm>
#include <vector>
using namespace std;

// Approach Name: Sorting + Greedy Interval Merging
// Time ciomplexity = O(n log n)
// Space complexity = O(n)

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    vector<int> prev = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= prev[1]) {
        prev[1] = max(prev[1], intervals[i][1]);
      } else {
        merged.push_back(prev);
        prev = intervals[i];
      }
    }

    merged.push_back(prev);

    return merged;
  }
};