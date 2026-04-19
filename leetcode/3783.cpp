#include <algorithm>
using namespace std;

// Approach name: Digit Reversal + Absolute Difference
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int rev = 0;
        while (temp > 0) {
            rev = (rev * 10) + (temp % 10);
            temp /= 10;
        }
        return abs(rev - n);
    }
};