#include <algorithm>
#include <climits>
#include <numeric>
// required for iota
#include <stack>
#include <vector>
using namespace std;

// Approach Name: Dynamic Programming + Monotonic Stack
// Monotonic Stack -> for Previous/Next Greater Element
// DAG-style DP -> on heights
// Time ciomplexity = O(n log n + n * d)
// Space complexity = O(n)

class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();

    vector<int> nge(n, INT_MAX);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] < arr[i]) st.pop();

      if (!st.empty()) {
        nge[i] = st.top();
      }
      st.push(i);
    }

    while (!st.empty()) st.pop();

    vector<int> pge(n, -1);
    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] < arr[i]) st.pop();

      if (!st.empty()) {
        pge[i] = st.top();
      }
      st.push(i);
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    // fill the vector (from indices start to end) with increasing values
    // (starting with the initial value)
    sort(indices.begin(), indices.end(),
         [&](int a, int b) { return arr[a] < arr[b]; });

    vector<int> dp(n, 1);

    for (int i : indices) {
      // Right jumps
      for (int x = 1; x <= d; x++) {
        int idx = i + x;

        if (idx >= n || idx >= nge[i]) break;

        dp[i] = max(dp[i], dp[idx] + 1);
      }

      // Left jumps
      for (int x = 1; x <= d; x++) {
        int idx = i - x;

        if (idx < 0 || idx <= pge[i]) break;

        dp[i] = max(dp[i], dp[idx] + 1);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};