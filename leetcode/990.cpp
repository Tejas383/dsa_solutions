#include <bits/stdc++.h>
using namespace std;

// Approach Name: Union-Find with Path Compression
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
  vector<char> parent;

  void makeUnion(char a, char b) {
    char parentA = find(a);
    char parentB = find(b);

    if (parentA == parentB) {
      return;
    }

    parent[parentA - 'a'] = parentB;
  }

  char find(char c) {
    if (parent[c - 'a'] == c) return c;

    return parent[c - 'a'] = find(parent[c - 'a']);
  }

 public:
  bool equationsPossible(vector<string>& equations) {
    parent.resize(26);
    for (int i = 0; i < 26; i++) {
      parent[i] = i + 'a';
    }

    for (auto eqn : equations) {
      if (eqn[1] == '=') {
        makeUnion(eqn[0], eqn[3]);
      }
    }

    for (auto eqn : equations) {
      if (eqn[1] == '!') {
        if (find(eqn[0]) == find(eqn[3])) return false;
      }
    }

    return true;
  }
};