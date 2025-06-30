#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& result){
        vis[node]=1;
        result.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<int>vis(V,0);
        int start=0;
        vector<int>result;
        dfs(start,adj,vis,result);
        return result;
        
    }
};