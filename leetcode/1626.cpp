#include <bits/stdc++.h>
using namespace std;

// Approach Name: Dynamic Programming (LIS on Sorted Age-Score Pairs)
// Time Complexity: O(n²)
// Space Complexity: O(n)

class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
      vec.push_back({ages[i], scores[i]});
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = vec[i].second;
      ans = max(ans, dp[i]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (vec[i].second < vec[j].second) continue;
        int a = vec[i].second + dp[j];
        dp[i] = max(dp[i], a);
        ans = max(ans, dp[i]);
      }
    }

    return ans;
  }
};