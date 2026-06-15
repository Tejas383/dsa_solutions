#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window
// Time ciomplexity = O(n log k)
// Space complexity = O(n)

// Idea: Maintain a window containing only unique characters.
// Expand the window when the next character is not present.
// If a duplicate is found,
// shrink the window from the left until the previous occurrence of that
// character is removed.

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char, bool> pres;

    int start = 0;
    int len = 0;
    int ans = 0;

    for (auto c : s) {
      if (pres.find(c) == pres.end() || pres[c] == false) {
        pres[c] = true;
        len++;
      } else {
        while (true) {
          pres[s[start]] = false;
          len--;

          if (s[start] == c) {
            start++;
            len++;
            break;
          }

          start++;
        }

        pres[c] = true;
      }

      ans = max(len, ans);
    }

    return ans;
  }
};