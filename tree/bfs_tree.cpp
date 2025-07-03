#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);  // 🌐 Level end marker
        vector<vector<int>> result;
        vector<int> level;

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (!node) {
                result.push_back(level);  // ✅ Save current level
                level.clear();
                if (!q.empty()) q.push(nullptr);  // ➕ Add marker for next level
            } else {
                level.push_back(node->val);  // 📥 Visit node
                if (node->left) q.push(node->left);   // ⬅️ Left
                if (node->right) q.push(node->right); // ➡️ Right
            }
        }

        return result;
    }
};