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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            if(val > root->val){
                root=root->right;
            }
            else root=root->left;
        }
        return root;

    }
};