#include <vector>
using namespace std;

// Approach Name: Frequency Counting
// Time ciomplexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> arr(A.size());
    int n = arr.size();

    vector<int> freq(n + 1, 0);

    int count = 0;

    for (int i = 0; i < n; i++) {
      freq[A[i]]++;
      if (freq[A[i]] == 2) count++;

      freq[B[i]]++;
      if (freq[B[i]] == 2) count++;

      arr[i] = count;
    }

    return arr;
  }
};