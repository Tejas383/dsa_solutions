#include <bits/stdc++.h>
using namespace std;

// Approach name : Stack-Based Parentheses Matching
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;

    for (const auto& c : s) {
      if (st.empty() && (c == ')' || c == ']' || c == '}')) return false;

      if (c == '(' || c == '[' || c == '{') st.push(c);

      if (c == ')')
        if (st.top() == '(')
          st.pop();
        else
          return false;

      if (c == ']')
        if (st.top() == '[')
          st.pop();
        else
          return false;

      if (c == '}')
        if (st.top() == '{')
          st.pop();
        else
          return false;
    }

    return st.empty() ? true : false;
  }
};