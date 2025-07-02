//Max and min element in Binary Tree GFG
/*

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    int findMax(Node *root) {
        // code here
        if(root==nullptr){
            return INT_MIN;
        }
        int leftmax=findMax(root->left);
        int rightmax=findMax(root->right);
        return max(root->data,max(leftmax,rightmax));
    }

    int findMin(Node *root) {
        
        // code here
        if(root==nullptr){
            return INT_MAX;
        }
        int rmin=findMin(root->right);
        int lmin=findMin(root->left);
        return min(root->data,min(rmin,lmin));
    }
};
