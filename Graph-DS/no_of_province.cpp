#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // Convert adjacency matrix to adjacency list
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int provinceCount = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                provinceCount++;
            }
        }
        return provinceCount;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    Solution sol;
    cout << "Number of Provinces: " << sol.findCircleNum(isConnected) << endl;
    return 0;
}
