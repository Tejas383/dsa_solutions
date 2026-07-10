#include <bits/stdc++.h>
using namespace std;

// Approach Name: Segment Tree (Range Maximum Query + First Valid Position
// Search) Time ciomplexity = O(n log n) Space complexity = O(n)

class Solution {
  void buildTree(vector<int>& baskets, int start, int end, int idx, vector<int>& segTree) {
    if (start == end) {
      segTree[idx] = baskets[start];
      return;
    }

    int mid = (start + end) / 2;
    buildTree(baskets, start, mid, 2 * idx + 1, segTree);
    buildTree(baskets, mid + 1, end, 2 * idx + 2, segTree);

    segTree[idx] = max(segTree[2 * idx + 1], segTree[2 * idx + 2]);
  }

  bool searchTree(int val, int start, int end, int idx, vector<int>& segTree) {
    if (segTree[idx] < val) return false;

    if (start == end) {
      segTree[idx] = -1;
      return true;
    }

    int mid = (start + end) / 2;

    if (segTree[2 * idx + 1] >= val)
      searchTree(val, start, mid, 2 * idx + 1, segTree);
    else
      searchTree(val, mid + 1, end, 2 * idx + 2, segTree);

    segTree[idx] = max(segTree[2 * idx + 1], segTree[2 * idx + 2]);

    return true;
  }

 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();

    vector<int> segTree(4 * n);
    buildTree(baskets, 0, n - 1, 0, segTree);

    int cnt = 0;

    for (auto fruit : fruits) {
      if (!searchTree(fruit, 0, n - 1, 0, segTree)) 
        cnt++;
    }

    return cnt;
  }
};