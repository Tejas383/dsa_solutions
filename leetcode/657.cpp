#include <string>
using namespace std;

// Approach name: Simulation (Coordinate Tracking)
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
public:
    bool judgeCircle(string moves) {
        int vert = 0;
        // move left: vert - 1
        // move right: vert + 1
        int hor = 0;
        // move up: hor + 1
        // move down: hor - 1

        for (char dir : moves) {
            switch (dir) {
                case 'U':
                    hor++;
                    break;
                case 'D':
                    hor--;
                    break;
                case 'R':
                    vert++;
                    break;
                case 'L':
                    vert--;
                    break;
            }
        }

        return (vert == 0 && hor == 0);
    }
};