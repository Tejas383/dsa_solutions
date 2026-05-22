#include <queue>
#include <vector>
using namespace std;

// Approach Name: Breadth First Search (BFS) on Array Indices
// Time ciomplexity = O(n^2)
// Space complexity = O(n)

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();

    vector<bool> vis(n, false);
    queue<int> q;

    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      if (node == n - 1) return true;

      int len = nums[node];
      for (int i = 1; i <= len; i++) {
        int nextIdx = node + i;
        if (nextIdx < n && !vis[nextIdx]) {
          q.push(nextIdx);
          vis[nextIdx] = true;
        }
      }
    }

    return false;
  }
};