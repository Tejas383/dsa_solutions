#include <bits/stdc++.h>
using namespace std;

// Link: https://www.hackerrank.com/challenges/crush/problem
// Approach Name: Difference Array (Prefix Sum / Range Update Technique)
// Time complexity = O(n)
// Space complexity = O(n)

long arrayManipulation(int n, vector<vector<int>> queries) {
  vector<long long> arr(n, 0);

  for (auto q : queries) {
    arr[q[0] - 1] += q[2];
    if (q[1] < n) arr[q[1]] -= q[2];
  }

  long long a = 0;
  long long ans = 0;

  for (auto val : arr) {
    a += val;
    ans = max(a, ans);
  }

  return ans;
}