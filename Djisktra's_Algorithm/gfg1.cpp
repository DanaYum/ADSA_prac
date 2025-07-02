// Shortest Distance in a Binary Maze

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        if(source==destination)
        return 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r + dr[i];
                int ncol=c + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && d+1 < dist[nrow][ncol] ){
                    dist[nrow][ncol]=d +1;
                    if(nrow==destination.first && ncol==destination.second){
                        return d+1;
                    }
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        return -1;
        
    }
};
