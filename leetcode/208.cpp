#include <bits/stdc++.h>
using namespace std;

class Trie {
 public:
  bool isEndOfWord;
  vector<Trie*> children;

  Trie() {
    isEndOfWord = false;
    children.resize(26);
  }

  void insert(string word) {
    Trie* crawl = this;

    for (auto c : word) {
      if (crawl->children[c - 'a'] == NULL) {
        crawl->children[c - 'a'] = new Trie();
      }
      crawl = crawl->children[c - 'a'];
    }

    crawl->isEndOfWord = true;
  }

  bool search(string word) {
    Trie* crawl = this;

    for (auto c : word) {
      if (crawl->children[c - 'a'] == NULL) return false;
      crawl = crawl->children[c - 'a'];
    }

    return crawl->isEndOfWord;
  }

  bool startsWith(string prefix) {
    Trie* crawl = this;

    for (auto c : prefix) {
      if (crawl->children[c - 'a'] == NULL) return false;
      crawl = crawl->children[c - 'a'];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */