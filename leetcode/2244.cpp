#include <bits/stdc++.h>
using namespace std;

// Approach Name: Frequency Counting + Greedy
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> freq;

    for (auto task : tasks) freq[task]++;

    int rounds = 0;

    for (auto p : freq) {
      int n = p.first;
      int f = p.second;

      if (f == 1) return -1;

      if (f % 3 == 2) {
        f -= 2;
        rounds++;
      }

      if (f % 3 == 1) {
        f -= 4;
        rounds += 2;
      }

      rounds += f / 3;
    }

    return rounds;
  }
};