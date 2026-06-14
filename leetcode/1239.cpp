#include <bits/stdc++.h>
using namespace std;

// Approach name: using DFS (take, not take problem)
// Time Complexity = O(2^n × 26)
// Space Complexity = O(n)

class Solution {
 public:
  bool isValid(string curr, string next) {
    map<char, int> freq;

    for (auto c : curr) {
      freq[c]++;
      if (freq[c] > 1) return false;
    }

    for (auto c : next) {
      freq[c]++;
      if (freq[c] > 1) return false;
    }

    return true;
  }

  void helper(vector<string>& arr, int start, string curr, int& maxLength) {
    if (maxLength < curr.size()) maxLength = curr.size();

    for (int i = start; i < arr.size(); i++) {
      if (isValid(curr, arr[i])) helper(arr, i + 1, curr + arr[i], maxLength);
    }
  }

  int maxLength(vector<string>& arr) {
    int maxLength = 0;
    helper(arr, 0, "", maxLength);
    return maxLength;
  }
};