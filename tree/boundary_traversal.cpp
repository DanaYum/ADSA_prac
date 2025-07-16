//Tree Boundary Traversal GFG
#include<bits/stdc++.h>
using namespace std;
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }

    void addLeftBoundary(Node* root, vector<int>& result) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) {
                result.push_back(cur->data);
            }
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& result) {
        Node* cur = root->right;
        vector<int> temp;
        while (cur) {
            if (!isLeaf(cur)) {
                temp.push_back(cur->data);
            }
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }

    void addLeafNodes(Node* root, vector<int>& result) {
        if (!root) return;
        if (isLeaf(root)) {
            result.push_back(root->data);
            return;
        }
        addLeafNodes(root->left, result);
        addLeafNodes(root->right, result);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> result;
        if (root == NULL) return result;
        if (!isLeaf(root)) {
            result.push_back(root->data);
        }
        addLeftBoundary(root, result);
        addLeafNodes(root, result);
        addRightBoundary(root, result);
        return result;
    }
};
