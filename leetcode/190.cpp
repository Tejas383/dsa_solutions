#include <bits/stdc++.h>
using namespace std;

// Approach Name: Bit Manipulation — Extract, Shift, and Append : similar to reversing a number
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int bit = n & 1;
            ans = (ans << 1) + bit;
            n = n >> 1;
        }
        
        return ans;
    }
};