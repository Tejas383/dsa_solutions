#include <bits/stdc++.h>
using namespace std;

// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string str) {
    vector<string> ans;

    if (str.size() < 10) return ans;

    unordered_map<string, int> m;

    int i = 0;
    while (i <= str.size() - 10) {
      string part = str.substr(i, 10);
      i++;

      m[part]++;
    }

    for (auto p : m) {
      if (p.second > 1) ans.push_back(p.first);
    }

    return ans;
  }
};