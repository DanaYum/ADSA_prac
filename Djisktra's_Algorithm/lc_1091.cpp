//1091. Shortest Path in Binary Matrix
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        if(n==1){
            if(grid[0][0]==0){
                return 1;
            }
            else return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        q.push({0,{0,0}});
        int dr[8]={-1,-1,0,1,1,1,0,-1};
        int dc[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0
                && d+1 < dist[nrow][ncol]){
                    dist[nrow][ncol]=d+1;
                    if(nrow==(n-1) && ncol==(m-1)){
                        return dist[nrow][ncol]+1;
                    }
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};