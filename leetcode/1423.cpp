#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sliding Window on the Chosen Cards (Take from Left and Right)
// Time complexity = O(k)
// Space complexity = O(k)

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int score = 0;
    int sum = 0;

    int i;
    for (i = 0; i < k; i++) {
      sum += cardPoints[i];
    }
    i--;

    score = sum;
    int j = cardPoints.size() - 1;

    while (i >= 0) {
      sum -= cardPoints[i--];
      sum += cardPoints[j--];

      score = max(score, sum);
    }

    return score;
  }
};