#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion (Brute Force - Take/Skip)
// Time complexity = O(2 ^ n)
// Space complexity = O(n)

class Solution {
  int helper(int i, int n, vector<int>& nums) {
    if (i >= n) return 0;

    return max(nums[i] + helper(i + 2, n, nums), helper(i + 1, n, nums));
  }

 public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int a = helper(0, n - 1, nums);
    int b = helper(1, n, nums);

    return max(a, b);
  }
};

// Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
  vector<int> dp1;
  vector<int> dp2;

  int helper(int i, int n, vector<int>& nums, vector<int>& dp) {
    if (i >= n) return 0;

    if (dp[i] != -1) return dp[i];

    return dp[i] = max(nums[i] + helper(i + 2, n, nums, dp),
                       helper(i + 1, n, nums, dp));
  }

 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    dp1.resize(n, -1);
    dp2.resize(n, -1);

    if (n == 1) return nums[0];

    int a = helper(0, n - 1, nums, dp1);
    int b = helper(1, n, nums, dp2);

    return max(a, b);
  }
};

// Approach 3: Bottom-Up Dynamic Programming (Tabulation)
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> dp1(n, 0);
    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n - 1; i++) {
      dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
    }

    vector<int> dp2(n, 0);
    dp2[1] = nums[1];
    dp2[2] = max(nums[1], nums[2]);

    for (int i = 3; i < n; i++) {
      dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
  }
};