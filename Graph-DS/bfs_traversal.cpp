#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V=adj.size();
        vector<int>visited(V,0);
        queue<int>q;
        vector<int> bfs;
        visited[0]=1;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
        
        
        
    }
};