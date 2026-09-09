#include <bits/stdc++.h>
using namespace std;

// Approach Name: Mathematical / Range-Based Counting
// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
 public:
  long long countCommas(long long n) {
    long long ans = 0;
    if (n < pow(10, 3)) return ans;

    ans += n - (pow(10, 3) - 1);
    if (n < pow(10, 6)) return ans;

    ans += n - (pow(10, 6) - 1);
    if (n < pow(10, 9)) return ans;

    ans += n - (pow(10, 9) - 1);
    if (n < pow(10, 12)) return ans;

    ans += n - (pow(10, 12) - 1);
    if (n < pow(10, 15)) return ans;

    ans += n - (pow(10, 15) - 1);
    return ans;
  }
};