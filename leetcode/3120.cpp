#include <set>
#include <string>
using namespace std;

// Approach Name: Hashing using Sets / Character Tracking
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int numberOfSpecialChars(string word) {
    set<char> upper;
    for (auto letter : word) {
      if (isupper(letter)) upper.insert(letter);
    }

    set<char> lower;
    int cnt = 0;
    for (auto letter : word) {
      if (islower(letter) && lower.find(letter) == lower.end() &&
          upper.find(toupper(letter)) != upper.end())
        cnt++;
      lower.insert(letter);
    }

    return cnt;
  }
};