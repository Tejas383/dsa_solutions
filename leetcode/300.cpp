#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force Recursion
// Time complexity = O(2^n)
// Space complexity = O(n) (recursion stack)

class Solution {
  int helper(int curr, int prev, auto& nums) {
    if (curr == nums.size()) return 0;

    int take = 0;
    if (prev == -1 || nums[curr] > nums[prev])
      take = 1 + helper(curr + 1, curr, nums);
    int skip = helper(curr + 1, prev, nums);

    return max(take, skip);
  }

 public:
  int lengthOfLIS(vector<int>& nums) { 
    return helper(0, -1, nums); 
  }
};

// Approach 2: Dynamic Programming (Memoization)
// Time complexity = O(n^2)
// Space complexity = O(n^2) + O(n) (DP table + recursion stack)

class Solution {
  int helper(int curr, int prev, auto& nums, auto& dp) {
    if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

    if (curr == nums.size()) return dp[curr][prev + 1] = 0;

    int take = 0;
    if (prev == -1 || nums[curr] > nums[prev])
      take = 1 + helper(curr + 1, curr, nums, dp);
    int skip = helper(curr + 1, prev, nums, dp);

    return dp[curr][prev + 1] = max(take, skip);
  }

 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper(0, -1, nums, dp);
  }
};

// Approach 3: Dynamic Programming (Tabulation)
// Time complexity = O(n^2)
// Space complexity = O(n)

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++)
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};

// Approach 4: Binary Search (Patience Sorting)
// Time complexity = O(n log n)
// Space complexity = O(n)

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;

    for (const auto& num : nums) {
      if (lis.empty() || num > lis[lis.size() - 1])
        lis.push_back(num);
      else {
        int low = 0;
        int high = lis.size() - 1;
        int mid;

        while (low < high) {
          mid = (low + high) / 2;

          if (lis[mid] < num)
            low = mid + 1;
          else
            high = mid;
        }

        lis[low] = num;
      }
    }

    return lis.size();
  }
};