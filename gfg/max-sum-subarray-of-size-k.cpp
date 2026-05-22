#include <algorithm>
#include <vector>
using namespace std;

// Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Approach Name: Sliding Window
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int maxSubarraySum(vector<int>& arr, int k) {
    // code here
    int sum = 0;
    int i = 0;
    while (i < k) {
      sum += arr[i++];
    }

    int maxSum = sum;

    int j = 0;
    while (i < arr.size()) {
      sum += arr[i++];
      sum -= arr[j++];

      maxSum = max(sum, maxSum);
    }

    return maxSum;
  }
};