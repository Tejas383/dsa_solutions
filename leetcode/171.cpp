#include <bits/stdc++.h>
using namespace std;

// Approach Name: Base-26 Conversion with 1-Based Character Mapping
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    long long ans = 0;
    for (int i = 0; i < columnTitle.size(); i++) {
      ans = ans * 26 + columnTitle[i] - 'A' + 1;
    }
    return ans;
  }
};