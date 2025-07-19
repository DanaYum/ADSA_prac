#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    void f(Node* root,vector<int>& ans){
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            Node* node=q.front().first;
            int line=q.front().second;
            q.pop();
            mpp[line]=node->data;
            if(node->left){
                q.push({node->left,line-1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
    }
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        f(root,ans);
        return ans;
        
    }
};