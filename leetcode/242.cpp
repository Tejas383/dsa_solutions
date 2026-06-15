#include <bits/stdc++.h>
using namespace std;

// Approach Name: Frequency Counting
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++) {
      int idxS = s[i] - 'a';
      int idxT = t[i] - 'a';

      freq[idxS]++;
      freq[idxT]--;
    }

    for (auto f : freq) {
      if (f != 0) return false;
    }

    return true;
  }
};