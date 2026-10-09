#include <bits/stdc++.h>
using namespace std;

// Approach: Palindrome Generation + Primality Testing
// Time Complexity: O(N * sqrt(N))
// Space Complexity: O(log N)

class Solution {
  bool prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) return false;
    }

    return true;
  }

  int createPalindrome(int n) {
    int pal = n;
    int temp = n / 10;

    while (temp > 0) {
      pal = pal * 10 + temp % 10;
      temp /= 10;
    }

    return pal;
  }

 public:
  int primePalindrome(int n) {
    if (n <= 2) return 2;
    if (n <= 3) return 3;
    if (n <= 5) return 5;
    if (n <= 7) return 7;
    if (n <= 11) return 11;

    int num = 1;
    while (true) {
      int pal = createPalindrome(num);
      if (pal >= n && prime(pal)) return pal;
      num++;
    }
  }
};