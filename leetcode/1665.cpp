#include <algorithm>
#include <vector>
using namespace std;

// Approach name: Greedy Sorting by Extra Required Energy
// Time Complexity = O(n log n)
// Time Complexity = O(1)

class Solution {
 public:
  static bool fn(vector<int> a, vector<int> b) {
    return ((a[1] - a[0]) < (b[1] - b[0]));
  }

  int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), fn);

    int ans = 0;
    for (auto task : tasks) {
      ans = max(ans + task[0], task[1]);
    }

    return ans;
  }
};