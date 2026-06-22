#include <bits/stdc++.h>
using namespace std;

// Approach Name: Frequency Counting
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> freq;
    freq['b'] = freq['a'] = freq['l'] = freq['o'] = freq['n'] = 0;

    for (auto t : text) {
      if (freq.find(t) != freq.end()) freq[t]++;
    };

    int count =
        min({freq['b'], freq['a'], freq['l'] / 2, freq['o'] / 2, freq['n']});

    return count;
  }
};