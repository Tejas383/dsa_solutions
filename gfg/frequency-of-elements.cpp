#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/frequency-of-elements--111353/1

// Approach Name: Hash Map
// Time ciomplexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  vector<vector<int>> countFreq(vector<int>& arr) {
    // code here
    map<int, int> freq;

    for (auto num : arr) {
      freq[num]++;
    }

    vector<vector<int>> ans;
    for (auto p : freq) {
      ans.push_back({p.first, p.second});
    }

    return ans;
  }
};