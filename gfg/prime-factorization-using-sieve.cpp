#include <bits/stdc++.h>
using namespace std;

// Link:
// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1
// Approach: Smallest Prime Factor (SPF) Sieve
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

class Solution {
 public:
  void sieve() {}

  vector<int> findPrimeFactors(int n) {
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

    vector<int> primeFactors;
    while (n > 1) {
      primeFactors.push_back(spf[n]);
      n /= spf[n];
    }

    return primeFactors;
  }
};