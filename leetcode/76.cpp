#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window (Two Pointers) + Frequency Hash Map
// Time ciomplexity = O(m + n), where, m = t.size(), n = s.size()
// Space complexity = O(1)

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) 
      return "";

    unordered_map<char, int> freq;
    for (auto c : t) 
      freq[c]++;

    int count = 0;
    int start = 0;
    int ansStart = -1;
    int len = s.size() + 1;

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (freq[c] > 0)
        count++;
      freq[c]--;

      while (count == t.size()) {
        if (i - start + 1 < len) {
          len = i - start + 1;
          ansStart = start;
        }

        char ch = s[start];
        freq[ch]++;
        if (freq[ch] == 1) 
          count--;

        start++;
      }
    }

    if (ansStart < 0) 
      return "";
    return s.substr(ansStart, len);
  }
};