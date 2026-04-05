#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// problem link: https://atcoder.jp/contests/dp/tasks/dp_i
// Approach name: Top-Down Dynamic Programming (Memoization) on Probabilities
// Time Complexity = O(n^2)
// Space Complexity = O(n^2)

double calculate(int n, vector<double>& prob, int headsTaken, vector<vector<double>>& dp) {
  
  if (n < 0) {
    if (headsTaken > (int)(prob.size() / 2))
    return 1.0;
    return 0.0;
  }
  
  if (dp[n][headsTaken] != -1)
    return dp[n][headsTaken];

  double takeHead = prob[n] * calculate(n - 1, prob, headsTaken + 1, dp);
  double takeTail = (1 - prob[n]) * calculate(n - 1, prob, headsTaken, dp);
  
  return dp[n][headsTaken] = takeHead + takeTail;
}

int main() {
  int n;
  cin >> n;

  vector<double> prob(n);
  for (int i = 0; i < n; i++) {
    cin >> prob[i];
  }

  vector<vector<double>> dp(n, vector<double> (n + 1, -1));

  cout << fixed << setprecision(10);
  cout << calculate(n - 1, prob, 0, dp);

  return 0;
}