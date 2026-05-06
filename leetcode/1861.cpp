#include <algorithm>
#include <vector>
using namespace std;

// Approach: Simulation + Transpose & Reverse
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
 public:
  vector<vector<char>> rotate(vector<vector<char>>& boxGrid) {
    int n = boxGrid.size();
    int m = boxGrid[0].size();
    vector<vector<char>> rotated(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        rotated[i][j] = boxGrid[j][i];
      }
    }

    return rotated;
  }

  vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int n = boxGrid.size();
    int m = boxGrid[0].size();

    vector<vector<char>> ans;

    for (int i = 0; i < n; i++) {
      vector<char> row = boxGrid[i];
      int j = m - 1;
      int write = j;
      while (j >= 0) {
        if (row[j] == '*') {
          write = j - 1;
        } else if (row[j] == '#') {
          swap(row[j], row[write]);
          write--;
        }
        j--;
      }
      ans.push_back(row);
    }

    vector<vector<char>> rotated = rotate(ans);
    for (int i = 0; i < rotated.size(); i++)
      reverse(rotated[i].begin(), rotated[i].end());

    return rotated;
  }
};