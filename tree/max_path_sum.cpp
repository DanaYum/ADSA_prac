//124. Binary Tree Maximum Path Sum Hard Level need backtracking concept
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
    public:
    int maxPathDown(TreeNode* root,int & maxi){
        if(root==nullptr) return 0;
        int leftSum=max(0,maxPathDown(root->left,maxi));
        int rightSum=max(0,maxPathDown(root->right,maxi));
        maxi=max(maxi,root->val + leftSum+ rightSum);
        return root->val + max(leftSum,rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }
};