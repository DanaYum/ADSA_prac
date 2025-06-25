#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    // Hardcoded edges:
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    // If undirected graph, add reverse edges as well:
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(2);

    Solution sol;
    vector<int> bfsResult = sol.bfsOfGraph(V, adj);

    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}