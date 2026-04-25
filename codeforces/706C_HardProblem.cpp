#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Problem Link: https://codeforces.com/contest/706/problem/C

// Approach 1: Backtracking (Brute Force Recursion with Two Choices per State)
// Time Complexity: O(2 ^ n)
// Space Complexity: O(n)
// TLE on test 8
 
int solve(int n, string nextStr, vector<int>& cost, vector<string>& strings) {
  if (n == 0) {
    return 0;
  }
 
  int ans = INT_MAX;
 
  string currStr = strings[n - 1];
  string revCurrStr = currStr;
  reverse(revCurrStr.begin(), revCurrStr.end());
 
  // keep
  if (currStr <= nextStr) {
    int res = solve(n - 1, currStr, cost, strings);
    if (res != INT_MAX)
      ans = min(ans, res);
  }
 
  // definitely, at most one of the two conditions will work
 
  // reverse
  if (revCurrStr <= nextStr) {
    int res = solve(n - 1, revCurrStr, cost, strings);
    if (res != INT_MAX)
      ans = min(ans, res + cost[n - 1]);
  }
 
  return ans;
}
 
int main() {
  int n;
  cin >> n;
 
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
 
  vector<string> strings(n);
  for (int i = 0; i < n; i++) {
    cin >> strings[i];
  }
 
  string next = strings[n - 1];
  string revNext = next;
  reverse(revNext.begin(), revNext.end());
 
  int keep = solve(n - 1, next, cost, strings);
  int rev = solve(n - 1, revNext, cost, strings);
  if (rev != INT_MAX)
    rev += cost[n - 1];
 
  int ans = INT_MAX;
  ans = min(keep, rev);
 
  if (ans == INT_MAX)
    ans = -1;
  cout << ans;
 
  return 0;
}
