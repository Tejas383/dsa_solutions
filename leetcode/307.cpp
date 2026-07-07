#include <bits/stdc++.h>
using namespace std;

// Approach: Segment Tree
// Time Complexity: O(n)
// Space Complexity: O(4*n)

class NumArray {
  vector<int> segTree;
  int n;

  void buildTree(vector<int>& nums, int start, int end, int idx) {
    if (start == end) {
      segTree[idx] = nums[start];
      return;
    }

    int mid = (start + end) >> 1;
    // mid = (start + end) / 2

    buildTree(nums, start, mid, 2 * idx + 1);
    buildTree(nums, mid + 1, end, 2 * idx + 2);

    segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
  }

  void updateTree(int start, int end, int currIdx, int finalIdx, int val) {
    if (start == end) {
      segTree[currIdx] = val;
      return;
    }

    int mid = (start + end) >> 1;

    if (finalIdx <= mid)
      updateTree(start, mid, 2 * currIdx + 1, finalIdx, val);
    else
      updateTree(mid + 1, end, 2 * currIdx + 2, finalIdx, val);

    segTree[currIdx] = segTree[2 * currIdx + 1] + segTree[2 * currIdx + 2];
  }

  int sumTree(int start, int end, int left, int right, int idx) {
    // no overlap
    if (start > right || end < left) return 0;

    // full overlap
    if (start >= left && end <= right) return segTree[idx];

    // partial overlap
    int mid = (start + end) >> 1;
    return sumTree(start, mid, left, right, 2 * idx + 1) +
           sumTree(mid + 1, end, left, right, 2 * idx + 2);
  }

 public:
  NumArray(vector<int>& nums) {
    this->n = nums.size();
    segTree.resize(4 * n);
    buildTree(nums, 0, n - 1, 0);
  }

  void update(int index, int val) { updateTree(0, n - 1, 0, index, val); }

  int sumRange(int left, int right) {
    return sumTree(0, n - 1, left, right, 0);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */