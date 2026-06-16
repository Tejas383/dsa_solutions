#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

// Approach Name: Two Pointers + Sorting
// Time ciomplexity = O(n log n)
// Space complexity = O(1)

class Solution {
 public:
  int minMeetingRooms(vector<int>& start, vector<int>& end) {
    // code here
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i, j;
    i = j = 0;

    int occupied_rooms = 0;
    int ans = 0;

    while (i < start.size()) {
      if (start[i] < end[j]) {
        occupied_rooms++;
        i++;
        ans = max(ans, occupied_rooms);
      } else {
        occupied_rooms--;
        j++;
      }
    }

    return ans;
  }
};
