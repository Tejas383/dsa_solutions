#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Approach Name: Trie (Prefix Tree) Based Prefix Matching
// Time ciomplexity = O((m + n) * d)
// Space complexity = O(n * d)

class TrieNode {
 public:
  vector<TrieNode*> children = vector<TrieNode*>(10);

  TrieNode() {
    for (int i = 0; i < 10; i++) {
      children[i] = nullptr;
    }
  }
};

class Trie {
 public:
  TrieNode* root;

  Trie() { root = new TrieNode(); }

  void insert(int num) {
    TrieNode* node = root;

    string numStr = to_string(num);

    for (auto digit : numStr) {
      int idx = digit - '0';

      if (node->children[idx] == nullptr) node->children[idx] = new TrieNode;

      node = node->children[idx];
    }
  }

  int findLongestPrefix(int num) {
    TrieNode* node = root;

    string numStr = to_string(num);

    int len = 0;

    for (auto digit : numStr) {
      int idx = digit - '0';

      if (node->children[idx]) {
        len++;
        node = node->children[idx];
      } else
        break;
    }

    return len;
  }
};

class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Trie trie;

    for (auto num : arr1) trie.insert(num);

    int maxLen = 0;

    for (auto num : arr2) maxLen = max(maxLen, trie.findLongestPrefix(num));

    return maxLen;
  }
};