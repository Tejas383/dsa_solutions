#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion (Brute Force)
// Time complexity : O(2^(m + n) * (m + n))
// Space complexity : O(m + n) (Recursion stack)

class Solution {
  string helper(int i, int j, auto& str1, auto& str2) {
    if (i == str1.size() && j == str2.size()) return "";

    if (i == str1.size()) return str2.substr(j);

    if (j == str2.size()) return str1.substr(i);

    if (str1[i] == str2[j]) return str1[i] + helper(i + 1, j + 1, str1, str2);

    string take1 = str1[i] + helper(i + 1, j, str1, str2);
    string take2 = str2[j] + helper(i, j + 1, str1, str2);

    if (take1.size() < take2.size()) return take1;
    return take2;
  }

 public:
  string shortestCommonSupersequence(string str1, string str2) {
    return helper(0, 0, str1, str2);
  }
};

// Approach 2 : Recursion + Memoization (Top-Down DP)
// Time complexity : O(m * n * (m + n))
// Space complexity : O(m * n * (m + n)) + O(m + n)
// (DP stores strings + recursion stack)

class Solution {
  string helper(int i, int j, auto& str1, auto& str2, auto& dp) {
    if (i == str1.size() && j == str2.size()) return "";

    if (dp[i][j] != "") return dp[i][j];

    if (i == str1.size()) return dp[i][j] = str2.substr(j);

    if (j == str2.size()) return dp[i][j] = str1.substr(i);

    if (str1[i] == str2[j])
      return dp[i][j] = str1[i] + helper(i + 1, j + 1, str1, str2, dp);

    string take1 = str1[i] + helper(i + 1, j, str1, str2, dp);
    string take2 = str2[j] + helper(i, j + 1, str1, str2, dp);

    if (take1.size() < take2.size()) return dp[i][j] = take1;
    return dp[i][j] = take2;
  }

 public:
  string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();

    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
    return helper(0, 0, str1, str2, dp);
  }
};

// Approach 3 : LCS + Backtracking
// Time complexity : O(m * n)
// Space complexity : O(m * n)

class Solution {
  string helper(int i, int j, auto& str1, auto& str2, auto& dp) {
    if (i == str1.size() && j == str2.size()) return "";

    if (dp[i][j] != "") return dp[i][j];

    if (i == str1.size()) return dp[i][j] = str2.substr(j);

    if (j == str2.size()) return dp[i][j] = str1.substr(i);

    if (str1[i] == str2[j])
      return dp[i][j] = str1[i] + helper(i + 1, j + 1, str1, str2, dp);

    string take1 = str1[i] + helper(i + 1, j, str1, str2, dp);
    string take2 = str2[j] + helper(i, j + 1, str1, str2, dp);

    if (take1.size() < take2.size()) return dp[i][j] = take1;
    return dp[i][j] = take2;
  }

 public:
  string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (str1[i - 1] == str2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    string str = "";
    int i = m;
    int j = n;

    while (i > 0 && j > 0) {
      if (str1[i - 1] == str2[j - 1]) {
        str += str1[i - 1];
        i--, j--;
      } else if (dp[i - 1][j] > dp[i][j - 1]) {
        str += str1[i - 1];
        i--;
      } else {
        str += str2[j - 1];
        j--;
      }
    }

    if (i == 0) {
      while (j > 0) str += str2[--j];
    }
    if (j == 0) {
      while (i > 0) str += str1[--i];
    }

    reverse(str.begin(), str.end());
    return str;
  }
};