#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    //     visited[node] = true;
    //     for (int neighbor : adjList[node]) {
    //         if (!visited[neighbor]) {
    //             dfs(neighbor, adjList, visited);
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
    //     // Convert adjacency matrix to adjacency list
    //     vector<vector<int>> adjList(n);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (isConnected[i][j] == 1 && i != j) {
    //                 adjList[i].push_back(j);
    //             }
    //         }
    //     }

    //     vector<bool> visited(n, false);
    //     int provinceCount = 0;

    //     for (int i = 0; i < n; i++) {
    //         if (!visited[i]) {
    //             dfs(i, adjList, visited);
    //             provinceCount++;
    //         }
    //     }
    //     return provinceCount;
    // }
   
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }

        return count;
    }
};


