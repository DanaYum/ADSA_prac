#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class solution{
    public:
    void f(Node* root,vector<int>& ans){
        queue<pair<int,Node*>>q;
        map<int,int>mpp;
        q.push({0,root});
        while(!q.empty()){
            int line=q.front().first;
            Node* node=q.front().second;
            q.pop();
            if(mpp.find(line)==mpp.end()){
                mpp[line]=node->data;
            }
            if(node->left){
                q.push({line-1,node->left});
            }
            if(node->right!=nullptr){
                q.push({line+1,node->right});
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        

    }
    vector<int> topView(Node *root) {
        vector<int> ans;
        f(root,ans);
        return ans;
    }

};
