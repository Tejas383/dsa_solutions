#include <bits/stdc++.h>
using namespace std;

// Approach Name: Base-26 Conversion with 1-Based Index Adjustment
// Time Complexity: O(log n)(base 26)
// Space Complexity: O(log n)(base 26)

class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ans = "";

    while (columnNumber > 0) {
      columnNumber--;

      int c = columnNumber % 26;
      ans += char(c + 'A');

      columnNumber /= 26;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};