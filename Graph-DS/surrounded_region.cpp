#include<bits/stdc++.h>
using namespace std;
class Solution {
    // private:
    //     void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int delRow[], int delCol[]) {
    //         vis[row][col]=1;
    //         //check all 4 directions
    //         int n=mat.size();
    //         int m=mat[0].size();
    //         for(int i=0;i<4;i++){
    //             int nrow=row+delRow[i];
    //             int ncol=col+delCol[i];
    //             //check for valid cell
    //             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='0'){
    //                 dfs(nrow,ncol,vis,mat,delRow,delCol);
    //             }
    //         }
    //     }
    // public:
    // vector<vector<char>> fill(int n,int m, vector<vector<char>>& mat){
    //     vector<vector<int>> vis(n, vector<int>(m, 0));
    //     int delRow[]={-1,0,1,0};
    //     int delCol[]={0,1,0,-1};
    //     //traverse first row and last row n-row, m-col
    //     for(int j=0;j<m;j++){
    //         // first row
    //         if(!vis[0][j] && mat[0][j]=='O'){
    //             dfs(0,j,vis,mat,delRow,delCol);
    //         }
    //         // last row
    //         if(!vis[n-1][j] && mat[n-1][j]=='O'){
    //             dfs(n-1,j,vis,mat,delRow,delCol);

    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         // first col
    //         if(!vis[i][0] && mat[i][0]=='O'){
    //             dfs(i,0,vis,mat,delRow,delCol);
    //         }
    //         // last col
    //         if(!vis[i][m-1] && mat[i][m-1]=='O'){
    //             dfs(i,m-1,vis,mat,delRow,delCol);
    //         }
    //     }  
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(!vis[i][j] && mat[i][j]=='O'){
    //                 mat[i][j]='X';
    //             }
    //         }
    //     }
    //     return mat;
    // }
    
    private:
    void dfs(int row,int col, vector<vector<int>>& vis, vector<vector<char>>& board,int delrow[],int delcol[]){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row + delrow[i];
            int ncol=col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1 )&& !vis[i][j] && board[i][j]=='O'){
                    dfs(i,j,vis,board,delrow,delcol);
                    vis[i][j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
