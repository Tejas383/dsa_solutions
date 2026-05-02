// Approach name: Brute Force Simulation
// Time Complexity = O(n logn)
// Space Complexity = O(1)

class Solution {
 public:
  int rotate(int n) {
    if (n == 0 || n == 1 || n == 8) return n;
    if (n == 2) return 5;
    if (n == 5) return 2;
    if (n == 6) return 9;
    if (n == 9) return 6;
    return -1;
  }

  bool good(int num) {
    int temp = num;
    int rot = 0;
    int c = 0;

    while (temp > 0) {
      int n = temp % 10;
      if (rot == 0 && n == 0) c++;
      int r = rotate(n);
      if (r == -1) return false;
      rot = rot * 10 + r;
      temp /= 10;
    }

    int rev = 0;
    while (rot > 0) {
      rev = rev * 10 + rot % 10;
      rot /= 10;
    }

    while (c > 0) {
      rev *= 10;
      c--;
    }

    return (rev != num);
  }

  int rotatedDigits(int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
      if (good(i)) {
        count++;
      }
    }

    return count;
  }
};