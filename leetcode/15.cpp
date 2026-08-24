#include <bits/stdc++.h>
using namespace std;

// Approach name: Sorting + Hash Map
// Time Complexity: O(n²)
// Space Complexity: O(n)

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    unordered_map<int, int> mymap;
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++) mymap[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++) {
      int num1 = nums[i];
      if (num1 > 0) break;

      if (i > 0 && num1 == nums[i - 1]) continue;

      for (int j = i + 1; j < nums.size(); j++) {
        int num2 = nums[j];

        if (j > i + 1 && num2 == nums[j - 1]) continue;

        if (mymap.count(0 - num1 - num2) && j < mymap[0 - num1 - num2])
          ans.push_back({0 - num1 - num2, num1, num2});
      }
    }

    return ans;
  }
};