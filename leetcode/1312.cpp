#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Approach name: Longest-Common Subsequence (Longest Palindromic Subsequence)
// Time Complexity = O(n^2)
// Space Complexity = O(n^2)

// The number of letters to add is the (size of string) - (length of longest palindromic)
// Example:
// String = mbadm
// longest palindromic substring = mam
// number of letters to add = 5 - 3 = 2
// palindromic string = mbdadbm / mdbabdm

class Solution {
public:
    int minInsertions(string s) {
        string str = s;
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(str.size() + 1, vector<int> (str.size() + 1, 0));
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (str[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return s.size() - dp[s.size()][s.size()];
    }
};