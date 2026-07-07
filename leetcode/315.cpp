#include <bits/stdc++.h>
using namespace std;

// Approach: Segment Tree + Coordinate Compression
// Time Complexity: O(n logn)
// Space Complexity: O(4*n)

class Solution {
  void buildTree(int start, int end, int currIdx, int finalIdx, vector<int>& segTree) {
    if (start == end) {
      segTree[currIdx]++;
      return;
    }

    int mid = (start + end) >> 1;
    if (finalIdx <= mid)
      buildTree(start, mid, 2 * currIdx + 1, finalIdx, segTree);
    else
      buildTree(mid + 1, end, 2 * currIdx + 2, finalIdx, segTree);

    segTree[currIdx]++;
  }

  int search(vector<int>& segTree, int qstart, int qend, int start, int end, int idx) {
    if (qend < qstart) return 0;

    if (qend < start || qstart > end) return 0;

    if (qstart >= start && qend <= end) return segTree[idx];

    int mid = (qstart + qend) >> 1;
    return search(segTree, qstart, mid, start, end, 2 * idx + 1) +
           search(segTree, mid + 1, qend, start, end, 2 * idx + 2);
  }

 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> helper = nums;
    sort(helper.begin(), helper.end());
    
    // unique() -> removes the consecutiive dupllicate elements and keeps them
    // at front, and then returns the index of the next element which is the
    // first duplicate
    helper.erase(unique(helper.begin(), helper.end()), helper.end());
    // erase() -> removes elements from vector

    int n = helper.size();
    vector<int> segTree(4 * n, 0);

    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      auto idx = lower_bound(helper.begin(), helper.end(), nums[i]) - helper.begin();

      ans[i] = search(segTree, 0, n - 1, 0, idx - 1, 0);
      buildTree(0, n - 1, 0, idx, segTree);
    }

    return ans;
  }
};