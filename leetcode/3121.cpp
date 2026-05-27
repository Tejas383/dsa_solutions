#include <map>
#include <string>
using namespace std;

// Approach Name: Hash Map / Last & First Occurrence Tracking
// Time ciomplexity = O(n)
// Space complexity = O(1)

class Solution {
 public:
  int numberOfSpecialChars(string word) {
    map<char, int> idx;
    for (int i = 0; i < word.size(); i++) {
      if (isupper(word[i]) && idx.find(word[i]) == idx.end()) idx[word[i]] = i;
      if (islower(word[i])) idx[word[i]] = i;
    }

    int cnt = 0;
    for (char i = 'a'; i <= 'z'; i++) {
      if (idx.find(i) != idx.end() && idx.find(toupper(i)) != idx.end() &&
          idx[toupper(i)] > idx[i])
        cnt++;
    }

    return cnt;
  }
};