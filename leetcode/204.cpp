#include <bits/stdc++.h>
using namespace std;

// Approach: Sieve of Eratosthenes
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

class Solution {
 public:
  int countPrimes(int n) {
    if (n == 0 || n == 1)
      return 0;

    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;

    int count = 0;

    for (int i = 2; i < n; i++) {
      if (primes[i] == false) 
        continue;

      count++;

      for (int j = i; j < n; j += i) 
        primes[j] = false;
    }

    return count;
  }
};