#include <bits/stdc++.h>
using namespace std;

// Approach Name: Dynamic Programming (Store Largest Divisible Subset Ending at Each Index) 
// Time complexity = O(n²) 
// Space complexity = O(n²)

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> vec(n);

    for (int i = 0; i < n; i++) {
      vector<int> v;
      for (int j = 0; j <= i; j++) {
        if (v.empty()) v.push_back(nums[i]);
        if (!vec[j].empty() 
            && nums[i] % vec[j][vec[j].size() - 1] == 0 
            && vec[j].size() >= v.size()) {
          v = vec[j];
          v.push_back(nums[i]);
        }
      }
      vec[i] = v;
    }

    vector<int> ans;
    for (auto v : vec) {
      if (v.size() > ans.size()) ans = v;
    }

    return ans;
  }
};