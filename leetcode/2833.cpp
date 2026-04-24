#include <string>
using namespace std;

// Approach name: Greedy + Net Movement with Wildcard Optimization
// Time complexity = O(n)
// Space complexity = O(1)

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist = 0;
        int gaps = 0;
        for (auto move : moves) {
            if (move == 'L')
                dist--;
            else if (move == 'R')
                dist++;
            else
                gaps++;
        }

        return abs(dist) + gaps;
    }
};