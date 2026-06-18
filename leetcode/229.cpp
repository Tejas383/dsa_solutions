#include <bits/stdc++.h>
using namespace std;

// Approach Name: Extended Boyer-Moore's Majority Voting Algorithm
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int votes1, votes2;
    int candidate1, candidate2;

    votes1 = votes2 = 0;
    candidate1 = candidate2 = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (votes1 == 0 && nums[i] != candidate2) {
        votes1++;
        candidate1 = nums[i];
      } else if (votes2 == 0 && nums[i] != candidate1) {
        votes2++;
        candidate2 = nums[i];
      } else if (candidate1 == nums[i]) {
        votes1++;
      } else if (candidate2 == nums[i]) {
        votes2++;
      } else {
        votes1--;
        votes2--;
      }
    }

    int count1, count2;
    count1 = count2 = 0;

    for (auto num : nums) {
      if (num == candidate1)
        count1++;
      else if (num == candidate2)
        count2++;
    }

    vector<int> ans;

    if (count1 > nums.size() / 3) {
      ans.push_back(candidate1);
    }

    if (count2 > nums.size() / 3) {
      ans.push_back(candidate2);
    }

    return ans;
  }
};