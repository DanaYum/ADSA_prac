//103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        //int flag=0;// 0 -> left to right and 1 -> for right to left
        bool leftToRight=true;
        while(!queue.empty()){
            int size=queue.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=queue.front();
                queue.pop();
                int index=(leftToRight)?i:(size-i-1);
                row[index]=node->val;
                if(node->left){
                    queue.push(node->left);
                }
                if(node->right){
                    queue.push(node->right);
                }
            }
            leftToRight=!leftToRight;
            result.push_back(row);
        }
        return result;
    }
};