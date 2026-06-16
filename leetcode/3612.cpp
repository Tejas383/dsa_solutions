#include <bits/stdc++.h>
using namespace std;

// Approach Name: String Simulation
// Time ciomplexity = O(m)
// Space complexity = O(m)
// where, m is the length of the final generated string

class Solution {
 public:
  string processStr(string s) {
    string ans = "";

    for (char c : s) {
      if (ans.size() != 0) {
        if (c == '*')
          ans.pop_back();
        else if (c == '#')
          ans += ans;
        else if (c == '%')
          reverse(ans.begin(), ans.end());
      }

      if (isalpha(c)) ans += c;
    }

    return ans;
  }
};