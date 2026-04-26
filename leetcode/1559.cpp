#include <vector>
using namespace std;

// Approach Name: DFS (Depth First Search) with Parent Tracking
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
public:
    bool dfs(int i, int j, int pi, int pj, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;

        // up
        if ((i - 1) >= 0 && grid[i - 1][j] == grid[i][j]) {
            if (!vis[i - 1][j]) {
                if (dfs(i - 1, j, i, j, n, m, grid, vis))
                    return true;
            }
            else if (i - 1 != pi || j != pj)
                return true;
        }

        // down
        if ((i + 1) < n && grid[i + 1][j] == grid[i][j]) {
            if (!vis[i + 1][j]) {
                if (dfs(i + 1, j, i, j, n, m, grid, vis))
                    return true;
            }
            else if (i + 1 != pi || j != pj)
                return true;
        }

        // left
        if ((j - 1) >= 0 && grid[i][j - 1] == grid[i][j]) {
            if (!vis[i][j - 1]) {
                if (dfs(i, j - 1, i, j, n, m, grid, vis))
                    return true;
            }
            else if (i != pi || j - 1 != pj)
                return true;
        }

        // right
        if ((j + 1) < m && grid[i][j + 1] == grid[i][j]) {
            if (!vis[i][j + 1]) {
                if (dfs(i, j + 1, i, j, n, m, grid, vis))
                    return true;
            }
            else if (i != pi || j + 1 != pj)
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, n, m, grid, vis))
                        return true;
                }
            }
        }

        return false;
    }
};