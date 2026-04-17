#include <vector>
#include <string>
#include <climits>
using namespace std;

// Approach name: Circular Array Traversal in Both Directions
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int i = startIndex;
        int steps = 0;
        int ans = INT_MAX;
        while (steps < words.size()) {
            if (words[i] == target) {
                ans = min(ans, steps);
            }

            steps++;
            i--;

            if (i < 0)
                i = words.size() - 1;
        }
        
        if (ans == INT_MAX)
            return -1;
    
        steps = 0;
        // i = startIndex
        while (steps < words.size()) {
            if (words[i] == target) {
                ans = min(ans, steps);
            }

            steps++;
            i++;

            if (i >= words.size())
                i = 0;
        }

        return ans;
    }
};