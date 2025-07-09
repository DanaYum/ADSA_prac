#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n) {
        parent.resize(n+1);// Initialize parent array with size n+1 to handle 1-based indexing as well as 0 based indexing
        size.resize(n+1, 1);// Initialize size array with size n+1, each element starts with size 1
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each element is its own parent
            size[i] = 1; // Initially, each element is its own set of size 1
        }
    }
    int findUpar(int node){//find ultimate parent
        if(node==parent[node]){
            return node; // If the node is its own parent, return it
        }
        return parent[node] = findUpar(parent[node]); // Path compression: update the parent of the node to its grandparent
    }
    void unionBySize(int u, int v) {
        int pu = findUpar(u); // Find the ultimate parent of u
        int pv = findUpar(v); // Find the ultimate parent of v

        if (pu == pv) return; // If they are already in the same set, do nothing

        // Union by size: attach the smaller tree under the larger tree
        if (size[pu] < size[pv]) {
            parent[pu] = pv; // Attach u's tree under v's tree
            size[pv] += size[pu]; // Update the size of the new root
        } else {
            parent[pv] = pu; // Attach v's tree under u's tree
            size[pu] += size[pv]; // Update the size of the new root
        }
    }
};
int main(){
    DisjointSet ds(7); // Create a disjoint set with 7 elements (1 to 7)
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    // Check if elements are in the same set
    cout << "1 and 3 are in the same set: " << (ds.findUpar(1) == ds.findUpar(3)) << endl; // Should print 1 (true)
    cout << "4 and 7 are in the same set: " << (ds.findUpar(4) == ds.findUpar(7)) << endl; // Should print 0 (false)

    return 0;
}