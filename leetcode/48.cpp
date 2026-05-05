#include <algorithm>
#include <vector>
using namespace std;

// Approach 1: Layer-by-layer 4-way cyclic rotation
// Time Complexity = O(n^2)
// Space Complexity = O(1)

// Approach 1: Transpose + Reverse (Row-wise)
// Time Complexity = O(n^2)
// Space Complexity = O(1)

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    for (int i = 0; i < n; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};