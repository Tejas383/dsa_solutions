#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window using Hash Map
// Time complexity = O(n)
// Space complexity = O(min(n, charset))

// Idea: Maintain a window containing only unique characters.
// Expand the window when the next character is not present.
// If a duplicate is found,
// shrink the window from the left until the previous occurrence of that
// character is removed.

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> mymap;
    int i = 0;
    int j = 0;

    while (i < s.size()) {
      if (!mymap.count(s[i]) || mymap[s[i]] == 0)
        mymap[s[i++]]++;
      else
        mymap[s[j++]]--;

      ans = max(ans, i - j);
    }

    return ans;
  }
};