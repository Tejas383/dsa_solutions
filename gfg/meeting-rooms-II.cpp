#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

// Approach 1: Two Pointers + Sorting
// Time ciomplexity = O(n log n)
// Space complexity = O(1)

// Approach 1: Line Sweep
// Time ciomplexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int minMeetingRooms(vector<int>& start, vector<int>& end) {
    // code here
    int n = start.size();

    map<int, int> m;

    for (int i = 0; i < n; i++) {
      m[start[i]]++;
      m[end[i]]--;
    }

    int rooms = 0;
    int ans = 0;

    for (auto v : m) {
      rooms += v.second;
      ans = max(ans, rooms);
    }

    return ans;
  }
};
