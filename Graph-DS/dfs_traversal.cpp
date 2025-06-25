#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& result) {
        vis[node] = 1;
        result.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> result;
        int start=0; // Starting node for DFS, can be any valid node in the graph
        dfs(start, adj, vis, result); // Start DFS from node 0
        return result;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    // Hardcoded edges:
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[4].push_back(2);

    Solution sol;
    vector<int> dfsResult = sol.dfsOfGraph(V, adj);

    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
