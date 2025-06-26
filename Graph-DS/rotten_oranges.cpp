#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q; // Queue for BFS: ((row, col), time)
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited status

    // Step 1: Enqueue all initially rotten oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int tm = 0;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    // Step 2: BFS traversal to rot adjacent fresh oranges
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        tm = max(tm, t);

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2; // Mark it rotten
            }
        }
    }

    // Step 3: Check for any remaining fresh orange
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] != 2) {
                return -1;
            }
        }
    }

    return tm;
}
