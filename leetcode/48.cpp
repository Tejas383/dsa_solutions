#include <vector>
using namespace std;

// Approach 1: Layer-by-layer 4-way cyclic rotation
// Time Complexity = O(n^2)
// Space Complexity = O(1)

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = temp;
      }
    }
  }
};