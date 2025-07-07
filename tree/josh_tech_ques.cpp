//Given a binary tree and a target node value, find the value of the node that is immediately to the left of the target node on the same level.
 /*
           1
          / \
         2    3
          \  / \
           4 5  6 finds the left node of 5, which is 4.
*/

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findLeftNode(TreeNode* root, int target) {
    if (!root) return -1;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        TreeNode* prev = nullptr;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == target) {
                return (prev ? prev->val : -1);
            }

            prev = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    return -1; // target not found
}
