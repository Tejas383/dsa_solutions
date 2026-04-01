#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach name: Value-based Dynamic Programming (Knapsack DP on Values)
// Time Complexity: O(n * maxValue)
// Space Complexity: O(n * maxValue)

int main() {
  int n;
  cin >> n;

  int w;
  cin >> w;

  vector<int> weight;
  vector<int> value;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    weight.push_back(a);
    value.push_back(b);
  }
  
  // Compute maximum possible value (sum of all values)
  int maxValue = 0;
  for (int i = 0; i < n; i++) {
    maxValue += value[i];
  }

  int ans = 0;

  // dp[i][j] = minimum weight required to achieve value j using first i items
  vector<vector<long long>> dp(n + 1, vector<long long>(maxValue + 1, 1e18));

  // Base case:- Value 0 can always be achieved with weight 0
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= maxValue; j++) {
      // Take the current item
      long long take = 1e18;
      if (j >= value[i - 1]) {
        take = dp[i - 1][j - value[i - 1]] + weight[i - 1];
      }
      // skip the current item
      long long skip = dp[i - 1][j];
      dp[i][j] = min(take, skip);
    }
  }

  // Find maximum value that can be achieved with weight <= w
  for (int val = 0; val <= maxValue; val++) {
    if (dp[n][val] <= w) {
        ans = val;
    }
  }

  cout << ans;

  return 0;
}