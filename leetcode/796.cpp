#include <string>
#include <vector>
using namespace std;

// Approach name: KMP (Knuth–Morris–Pratt) String Matching
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    string str = s + s;
    string pat = goal;
    int n = s.size();

    vector<int> lps(n);  // lps of pattern (pat)
    lps[0] = 0;
    int l = 0;
    int i = 1;

    while (i < n) {
      if (pat[i] == pat[l]) {
        l++;
        lps[i] = l;
        i++;
      } else {
        if (l == 0) {
          lps[i] = 0;
          i++;
        } else
          l = lps[l - 1];
      }
    }

    i = 0;
    int j = 0;
    int m = str.size();

    while (i < m) {
      if (str[i] == pat[j]) {
        i++;
        j++;
      } else {
        if (j == 0)
          i++;
        else
          j = lps[j - 1];
      }

      if (j == pat.size()) return true;
    }

    return false;
  }
};