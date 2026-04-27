#include <vector>
#include <queue>
using namespace std;

// Approach name: BFS traversal with Valid edge connectivity
// Time Complexity : O(n * m)
// Space Complexity : O(n * m)

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {

        // direction[i] stores the allowed directions for road type i
        // Each direction is represented as (row_change, col_change)
        vector<vector<pair<int, int>>> direction(7);

        // Road type mappings:
        // 1 -> left, right
        direction[1] = {{0, -1}, {0, 1}};

        // 2 -> up, down
        direction[2] = {{-1, 0}, {1, 0}};

        // 3 -> left, down
        direction[3] = {{0, -1}, {1, 0}};

        // 4 -> right, down
        direction[4] = {{0, 1}, {1, 0}};

        // 5 -> up, left
        direction[5] = {{-1, 0}, {0, -1}};

        // 6 -> up, right
        direction[6] = {{-1, 0}, {0, 1}};

        int n = grid.size();
        int m = grid[0].size();

        // BFS queue
        queue<pair<int, int>> q;

        // Visited matrix to avoid re-processing cells
        vector<vector<int>> vis(n, vector<int>(m, false));

        // Start from top-left cell
        q.push({0, 0});
        vis[0][0] = true;

        // BFS traversal
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // If reached destination → valid path exists
            if (row == n - 1 && col == m - 1)
                return true;

            int road = grid[row][col];

            // Explore all directions allowed by current road
            for (auto dir : direction[road]) {

                int nextRow = row + dir.first;
                int nextCol = col + dir.second;

                // Boundary + visited check
                if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m || vis[nextRow][nextCol])
                    continue;

                int nextRoad = grid[nextRow][nextCol];

                // Now check if next cell connects back to current cell
                for (auto d : direction[nextRoad]) {

                    int cr = d.first;
                    int cc = d.second;

                    // Check reverse connectivity:
                    // If from next cell we can come back to current cell
                    if (nextRow + cr == row && nextCol + cc == col) {

                        vis[nextRow][nextCol] = true;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        // If BFS ends without reaching destination
        return false;
    }
};