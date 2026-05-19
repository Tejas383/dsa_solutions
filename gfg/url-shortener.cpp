#include <algorithm>
#include <string>
using namespace std;

// Problem link:
// https://www.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener2031/1#
// Approach name: Base-62 Encoding
// Time Complexity: O(log₆₂ n) - log n base 62
// Space Complexity: O(log₆₂ n) - log n base 62

class Solution {
 public:
  string idToShortURL(long long int n) {
    string charSet =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    string ans = "";
    while (n > 0) {
      ans += charSet[n % 62];
      n /= 62;
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};