//1319. Number of Operations to Make Network Connected
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int> parent,size,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUparent(parent[node]);
    }
    void byRank(int u,int v){
        int pu=findUparent(u);
        int pv=findUparent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void bySize(int u,int v){
        int pu=findUparent(u);
        int pv=findUparent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it: connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUparent(u)==ds.findUparent(v)){
                cntExtras++;
            }
            else{
                ds.bySize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }
        int ans=cntC-1;
        if(cntExtras>=ans) return ans;
        else return -1;
    }
};