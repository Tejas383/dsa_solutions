#include <bits/stdc++.h>
using namespace std;

// Approach Name: Bit Manipulation + Binary Trie (Prefix Trie)
// Time ciomplexity = O(32 * n) = O(n)
// Space complexity = O(32 * n) = O(n)

class Trie {
  vector<Trie*> children;

 public:
  Trie() { 
    children.resize(2); 
  }

  // insert the numbers in trie
  // since, the numbers can be of different bits, it is better to add them along
  // with the bits so, instead of 3 = 11, we do 3 = 00000011
  void insert(int num) {
    Trie* crawl = this;

    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (crawl->children[bit] == nullptr) 
        crawl->children[bit] = new Trie();

      crawl = crawl->children[bit];
    }
  }

  // Suppose, num = 5 (= 101).
  // To maximize the XOR, we prefer a number whose bits are opposite.
  // For example, 101 ^ 010 = 111 (maximum possible for 3 bits).
  // Hence, while traversing the trie, we greedily try to choose the opposite
  // bit at every position. If it doesn't exist, we choose the same bit.
  int search(int num) {
    Trie* crawl = this;

    int n = 0;

    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (crawl->children[!bit] != nullptr) {
        n = n * 2 + !bit;
        crawl = crawl->children[!bit];
      } else {
        n = n * 2 + bit;
        crawl = crawl->children[bit];
      }
    }

    return n ^ num;
  }
};

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    Trie* trie = new Trie();
    for (int num : nums)
      trie->insert(num);

    int ans = 0;
    for (int num : nums)
      ans = max(ans, trie->search(num));

    return ans;
  }
};