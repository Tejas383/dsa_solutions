#include <bits/stdc++.h>
using namespace std;

// Approach Name: Monotonic Stack + Contribution Technique
// Time complexity = O(n)
// Space complexity = O(n)

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int MOD = pow(10, 9) + 7;

    stack<int> st;

    vector<int> pse(n, -1);
    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] > arr[i]) 
        st.pop();

      if (!st.empty()) 
        pse[i] = st.top();

      st.push(i);
    }

    while (!st.empty())
      st.pop();

    vector<int> nse(n, n);
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] >= arr[i]) 
        st.pop();

      if (!st.empty()) 
        nse[i] = st.top();

      st.push(i);
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
      long long left = i - pse[i];
      long long right = nse[i] - i;

      long long cont = left * right;
      long long s = arr[i] * cont;
      sum = (sum + s) % MOD;
    }

    return sum;
  }
};