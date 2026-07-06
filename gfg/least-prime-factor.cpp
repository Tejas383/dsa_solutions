#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/least-prime-factor5216/1
// Approach: Sieve of Eratosthenes (Smallest Prime Factor - SPF)
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

class Solution {
 public:
  vector<int> leastPrimeFactor(int n) {
    // code here
    vector<int> spf(n + 1, 1);
    for (int i = 2; i <= n; i++) 
      spf[i] = i;

    for (int i = 2; i <= n; i++) {
      if (spf[i] != i) 
        continue;

      for (int j = i; j <= n; j += i) {
        if (spf[j] == j) 
          spf[j] = i;
      }
    }

    return spf;
  }
};