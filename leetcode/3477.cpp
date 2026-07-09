#include <bits/stdc++.h>
using namespace std;

// Approach Name: Brute Force
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();

    int count = n;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (baskets[j] >= fruits[i]) {
          baskets[j] = 0;
          count--;
          break;
        }
      }
    }

    return count;
  }
};