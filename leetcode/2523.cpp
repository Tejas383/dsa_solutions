#include <bits/stdc++.h>
using namespace std;

// Approach: Sieve of Eratosthenes + Linear Scan
// Time Complexity: O(right log log right)
// Space Complexity: O(right)

class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    vector<bool> prime(right + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= right; i++) {
      if (!prime[i])
        continue;

      for (int j = 2 * i; j <= right; j += i)
        prime[j] = false;
    }

    vector<int> p;

    for (int i = left; i <= right; i++) {
      if (prime[i]) 
        p.push_back(i);
    }

    if (p.size() <= 1) 
      return {-1, -1};

    int l = p[0];
    int r = p[1];
    for (int i = 1; i < p.size(); i++) {
      if (p[i] - p[i - 1] < r - l) {
        l = p[i - 1];
        r = p[i];
      }
    }

    return {l, r};
  }
};