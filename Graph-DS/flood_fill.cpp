#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, int iniColor, vector<vector<int>>& image,
             vector<vector<int>>& ans, int delRow[], int delCol[], int newColor) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                ans[nrow][ncol] != newColor && image[nrow][ncol] == iniColor) {
                dfs(nrow, ncol, iniColor, image, ans, delRow, delCol, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        if (iniColor == newColor) return image;  // Avoid unnecessary recursion
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, iniColor, image, ans, delRow, delCol, newColor);
        return ans;
    }
};

// Optional test driver
int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    // Print result
    for (auto& row : result) {
        for (auto& col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }

    return 0;
}
