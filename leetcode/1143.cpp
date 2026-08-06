#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion (Brute Force)
// Time complexity : O(2^(m + n))
// Space complexity : O(m + n) (Recursion stack)

class Solution {
  int helper(int i, int j, string& str1, string& str2) {
    if (i == str1.size() || j == str2.size()) return 0;

    if (str1[i] == str2[j]) return 1 + helper(i + 1, j + 1, str1, str2);

    return max(helper(i + 1, j, str1, str2), helper(i, j + 1, str1, str2));
  }

 public:
  int longestCommonSubsequence(string text1, string text2) {
    return helper(0, 0, text1, text2);
  }
};

// Approach 2 : Recursion + Memoization (Top-Down DP)
// Time complexity : O(m * n)
// Space complexity : O(m * n) + O(m + n) (DP table + Recursion stack)

class Solution {
  int helper(int i, int j, string& str1, string& str2, auto& dp) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i == str1.size() || j == str2.size()) return dp[i][j] = 0;

    if (str1[i] == str2[j])
      return dp[i][j] = 1 + helper(i + 1, j + 1, str1, str2, dp);

    return dp[i][j] = max(helper(i + 1, j, str1, str2, dp),
                          helper(i, j + 1, str1, str2, dp));
  }

 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(0, 0, text1, text2, dp);
  }
};

// Approach 3 : Tabulation (Bottom-Up DP)
// Time complexity : O(m * n)
// Space complexity : O(m * n)

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[m][n];
  }
};