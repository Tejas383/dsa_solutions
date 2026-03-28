// Approach 1: Recursion (Top-Down) / Brute Force

class Solution {
public:
  int reach(int m, int n) {
    if (m == 0 && n == 0)
      return 1;
    
    int up, left;
    up = left = 0;

    if (m != 0)
      up = reach(m - 1, n);
    if (n != 0)
      left = reach(m, n - 1);

    return up + left;
  }

  int uniquePaths(int m, int n) {
    return reach(m - 1, n - 1);
  }
};