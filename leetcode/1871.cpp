#include <queue>
#include <string>
#include <vector>
using namespace std;

// Approach Name: Optimized BFS using Sliding Window / Farthest Reach
// Time ciomplexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();

    if (s[n - 1] != '0') return false;

    queue<int> q;
    vector<bool> vis(n, false);
    int farthest = 0;

    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      if (node == n - 1) return true;

      for (int i = max(node + minJump, farthest);
           i <= min(node + maxJump, n - 1); i++) {
        if (!vis[i] && s[i] == '0') {
          q.push(i);
          vis[i] = true;
        }
        farthest = i;
      }
    }

    return false;
  }
};