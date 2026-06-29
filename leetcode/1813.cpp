#include <bits/stdc++.h>
using namespace std;

// Approach Name: Two-Pointer + Prefix-Suffix Matching
// Time complexity = O(n + m)
// Space complexity = O(n + m)

class Solution {
 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    if (sentence1.size() > sentence2.size()) 
      swap(sentence1, sentence2);

    // convert both the strings to string stream (for conversion to vector)
    stringstream ss1(sentence1);
    stringstream ss2(sentence2);

    // initialise the vectors
    vector<string> vec1;
    vector<string> vec2;

    // var (token) to store the string until the delimiter is encountered
    string token1;
    string token2;

    // to check that the next word exists
    // and push to vec
    while (getline(ss1, token1, ' ')) 
      vec1.push_back(token1);

    while (getline(ss2, token2, ' ')) 
      vec2.push_back(token2);

    int start = 0;
    int end1 = vec1.size() - 1;
    int end2 = vec2.size() - 1;

    // find common words from the beginning
    while (start < vec1.size() && vec1[start] == vec2[start]) 
      start++;

    // find common words from the end
    while (end1 >= 0 && vec1[end1] == vec2[end2]) 
      end1--, end2--;

    // If no words remain in the shorter sentence (end1 < start), then all its
    // words were matched
    return end1 < start;
  }
};