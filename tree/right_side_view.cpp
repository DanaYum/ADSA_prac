//199. Binary Tree Right Side View
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    void f(TreeNode* root,int level,vector<int>& res){
        if(root==NULL) return;
        if(level==res.size()){
            res.push_back(root->val);
        }
        f(root->right,level+1,res);
        f(root->left,level+1,res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int> res;
        f(root,level,res);
        return res;
    }
};