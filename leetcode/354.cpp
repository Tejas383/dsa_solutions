#include <bits/stdc++.h>
using namespace std;

// Approach Name: Sorting + Longest Increasing Subsequence (Patience Sorting)
// Time complexity = O(n log n)
// Space complexity = O(n)

class Solution {
  static bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
      return a[1] > b[1];
    else
      return a[0] < b[0];
  }

 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), comp);
    vector<int> lis;

    for (const auto& envelope : envelopes) {
      int bredth = envelope[1];

      if (lis.empty() || bredth > lis[lis.size() - 1])
        lis.push_back(bredth);
      else {
        int low = 0;
        int high = lis.size() - 1;
        int mid;

        while (low < high) {
          mid = (low + high) / 2;

          if (lis[mid] < bredth)
            low = mid + 1;
          else
            high = mid;
        }

        lis[low] = bredth;
      }
    }

    return lis.size();
  }
};