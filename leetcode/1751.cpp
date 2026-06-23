#include <bits/stdc++.h>
using namespace std;

// Approach Name: Greedy (Lexicographical Suffix Comparison)
// Time complexity = O(n ^ 2)
// Space complexity = O(1)

class Solution {
 public:
  string largestMerge(string word1, string word2) {
    string merge;

    int i = 0, j = 0;

    while (i < word1.size() && j < word2.size()) {
      // we are comparing the substring in word1 starting from i to end
      // with the substring in word2 starting from j to end
      if (word1.substr(i) > word2.substr(j))
        merge += word1[i++];
      else
        merge += word2[j++];
    }

    merge += word1.substr(i);
    merge += word2.substr(j);

    return merge;
  }
};