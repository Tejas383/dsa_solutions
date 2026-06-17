#include <bits/stdc++.h>
using namespace std;

// Approach Name: Reverse Simulation with Length Tracking
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  char processStr(string s, long long k) {
    long long len = 0;

    // compute the final length of string
    for (auto c : s) {
      if (c == '*') {
        if (len) len--;
      } else if (c == '#') {
        len *= 2;
      } else if (c == '%') {
        continue;
      } else {
        len++;
      }
    }

    // early return - k is outside the final length
    if (k >= len) return '.';

    // reverse simulation for finding the kth character
    for (int i = s.size() - 1; i >= 0; i--) {
      char c = s[i];

      if (c == '*') {
        // because the element was popped
        len++;
      } else if (c == '#') {
        // if k lies in the 2nd half,
        // find the corresponding index in the first half
        if (k >= (len + 1) / 2) k -= len / 2;
        len = (len + 1) / 2;
      } else if (c == '%') {
        // the string is reversed, find the corresponding index
        k = len - k - 1;
      } else {
        if (k == len - 1) return c;
        len--;
      }
    }

    return '.';
  }
};