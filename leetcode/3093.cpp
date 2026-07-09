#include <bits/stdc++.h>
using namespace std;

// Approach Name: Reversed Trie
// Time ciomplexity = O((N+M)×L)
// Space complexity = O(K)
// where,
// N = number of strings in wordsContainer
// M = number of query strings
// L = average string length
// K = total characters in wordsContainer

struct TrieNode {
  int index;
  TrieNode* children[26];
};

// constexpr -> at the time of compilation, the value must be an integer, not variable
// static -> to prevent stack overflow error, 
// since without static, the variable is allocated stack memory, 
// which is only of 8-10MB, but we are trying to allocate 120MB
static constexpr int MAX_NODES = 500000;
static TrieNode pool[MAX_NODES];
static int ptr = 0;

class Solution {
  TrieNode* getNode() {
    TrieNode* newNode = &pool[ptr++];
    newNode->index = -1;
    for (int i = 0; i < 26; i++) {
      newNode->children[i] = nullptr;
    }
    return newNode;
  }

  void insert(int i, vector<string>& arr, TrieNode* root) {
    TrieNode* crawl = root;
    if (crawl->index == -1 || arr[i].size() < arr[crawl->index].size() ||
        (arr[i].size() == arr[crawl->index].size() && i < crawl->index))
      crawl->index = i;

    string word = arr[i];
    reverse(word.begin(), word.end());

    for (auto w : word) {
      int idx = w - 'a';

      if (crawl->children[idx] == nullptr) 
        crawl->children[idx] = getNode();

      crawl = crawl->children[idx];

      if (crawl->index == -1 || arr[i].size() < arr[crawl->index].size() ||
          (arr[i].size() == arr[crawl->index].size() && i < crawl->index))
        crawl->index = i;
    }
  }

  int search(string word, TrieNode* root) {
    TrieNode* crawl = root;

    for (auto w : word) {
      int idx = w - 'a';

      if (crawl->children[idx] == nullptr) break;

      crawl = crawl->children[idx];
    }

    return crawl->index;
  }

 public:
  vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery) {
    ptr = 0;
    // If multiple test cases use the same Solution, we'll continue allocating
    // from the previous run. To escape this, we need to reset the ptr

    TrieNode* root = getNode();

    for (int i = 0; i < wordsContainer.size(); i++) {
      string word = wordsContainer[i];
      reverse(word.begin(), word.end());

      insert(i, wordsContainer, root);
    }

    vector<int> ans;
    for (auto word : wordsQuery) {
      reverse(word.begin(), word.end());

      ans.push_back(search(word, root));
    }

    return ans;
  }
};