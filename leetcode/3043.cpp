#include <bits/stdc++.h>
using namespace std;

// Approach Name: Trie (Prefix Tree) Based Prefix Matching
// Time ciomplexity = O((m + n) * d)
// Space complexity = O(n * d)

class Trie {
  vector<Trie*> children;

 public:
  Trie() { children.resize(10); }

  void insert(int num) {
    Trie* crawl = this;

    string str = to_string(num);
    for (auto s : str) {
      int idx = s - '0';
      if (crawl->children[idx] == nullptr) crawl->children[idx] = new Trie();
      crawl = crawl->children[idx];
    }
  }

  int search(int num) {
    Trie* crawl = this;

    string str = to_string(num);
    int len = 0;

    for (auto s : str) {
      int idx = s - '0';
      if (crawl->children[idx] != nullptr) {
        len++;
        crawl = crawl->children[idx];
      } else
        break;
    }

    return len;
  }
};

class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie* trie = new Trie();
    for (auto a : arr1) trie->insert(a);

    int ans = 0;
    for (auto a : arr2) ans = max(ans, trie->search(a));

    return ans;
  }
};