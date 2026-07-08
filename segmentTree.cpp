#include <bits/stdc++.h>
using namespace std;

void BuildTree(int l, int r, vector<int>& segTree, vector<int>& nums, int idx) {
  if (l >= nums.size() || r >= nums.size()) {
    segTree[idx] = 0;
    return;
  }

  if (l == r) {
    segTree[idx] = nums[l];
    return;
  }

  int mid = (l + r) / 2;

  BuildTree(l, mid, segTree, nums, 2 * idx + 1);
  BuildTree(mid + 1, r, segTree, nums, 2 * idx + 2);

  segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
}

int calcSum1(int l, int r, vector<int>& segTree, int tl, int tr, int idx) {
  if (l >= tl && r <= tr) return segTree[idx];

  if (l > tr || r < tl) return 0;

  int mid = (l + r) / 2;

  int sum = 0;
  // go left
  sum += calcSum1(l, mid, segTree, tl, tr, 2 * idx + 1);
  // go left
  sum += calcSum1(mid + 1, r, segTree, tl, tr, 2 * idx + 2);

  return sum;
}

void updateRange(int l, int r, vector<int>& segTree, int tl, int tr, int k,
                 vector<int>& lazyArray, int idx) {
  if (l >= tl && r <= tr) {
    // our range is completely in target range
    segTree[idx] += ((k + lazyArray[idx]) * (r - l + 1));
    lazyArray[2 * idx + 1] += (k + lazyArray[idx]);
    lazyArray[2 * idx + 2] += (k + lazyArray[idx]);
    lazyArray[idx] = 0;

    return;
  }

  if (l < tr || r < tl) return;

  int mid = (l + r) / 2;
  updateRange(l, mid, segTree, tl, tr, k, lazyArray, idx * 2 + 1);
  updateRange(mid + 1, r, segTree, tl, tr, k, lazyArray, idx * 2 + 2);
}

int main() {
  vector<int> nums = {5, 8, 10, 6, 9, 5, 11, 28};
  int n = nums.size();

  vector<int> segTree(4 * n);
  int l = 0;
  int r = n - 1;

  BuildTree(l, r, segTree, nums, 0);

  int tl = 1;
  int tr = 6;
  cout << calcSum1(l, r, segTree, tl, tr, 0) << endl;

  int k = 2;
  vector<int> lazyArray(4 * n, 0);
  updateRange(l, r, segTree, tl, tr, k, lazyArray, 0);

  return 0;
}