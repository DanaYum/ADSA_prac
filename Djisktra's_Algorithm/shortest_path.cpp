//Shortest Path in Weighted undirected graph GFG

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dist[1]=0;
        pq.push({1,0});
        while(!pq.empty()){
            int node=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode=it.first;
                int adjedge=it.second;
                if(d + adjedge < dist[adjNode]){
                    dist[adjNode]=d + adjedge;
                    pq.push({adjNode,dist[adjNode]});
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==INT_MAX){
            return {-1};
        }
        int node=n;
        vector<int> path;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        path.insert(path.begin(), dist[n]);  // insert total weight at the beginning

        return path;
    }
};