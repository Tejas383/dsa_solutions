#include <bits/stdc++.h>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
// Approach Name: Prefix XOR + Hash Map
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  long subarrayXor(vector<int>& arr, int k) {
    // code here
    unordered_map<int, int> freq;

    freq[0] = 1;

    int x = 0;

    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
      x ^= arr[i];

      int target = x ^ k;
      if (freq.count(target)) {
        count += freq[target];
      }

      freq[x]++;
    }

    return count;
  }
};