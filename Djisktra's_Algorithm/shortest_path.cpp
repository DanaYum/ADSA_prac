#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        // Min-heap: (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1);

        for(int i = 1; i <= n; i++) parent[i] = i;

        dist[1] = 0;
        pq.push({0, 1}); // (distance, node)

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;

                if(d + weight < dist[adjNode]){
                    dist[adjNode] = d + weight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        // No path found
        if(dist[n] == INT_MAX){
            return {-1};
        }

        // Reconstruct the path
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); // starting node
        reverse(path.begin(), path.end());

        // Insert total weight at the front
        path.insert(path.begin(), dist[n]);

        return path;
    }
};
int main() {
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    Solution obj;
    vector<int> result = obj.shortestPath(n, m, edges);

    if(result.size() == 1 && result[0] == -1){
        cout << "No path exists from 1 to " << n << endl;
    } else {
        cout << "Shortest Distance: " << result[0] << endl;
        cout << "Path: ";
        for(int i = 1; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}