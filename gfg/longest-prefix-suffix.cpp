#include <string>
#include <vector>
using namespace std;

// Approach name: KMP based LPS calculation
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int getLPSLength(string& s) {
    // code here
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    int l = 0;
    int i = 1;

    while (i < n) {
      if (s[i] != s[l]) {
        if (l == 0) {
          lps[i] = 0;
          i++;
        } else
          l = lps[l - 1];
      } else {
        l++;
        lps[i] = l;
        i++;
      }
    }

    return lps[n - 1];
  }
};