// User Function Template
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Convert edge list to adjacency list
        vector<pair<int, int>> adj[V];  // adj[u] = {v, wt}
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            // If the graph is undirected, also add:
            // adj[v].push_back({u, wt});
        }

        // Step 2: Min-heap priority queue: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Step 3: Distance vector, initialized to INF
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        
        // Step 4: Main loop
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
