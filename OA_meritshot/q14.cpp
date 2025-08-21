/*
14. Employee Hierarchy (Binary Tree)
Scenario:
A company wants to store employee names in a binary tree for hierarchy tracking.
Problem:
Create a binary tree.
Print the employee names using inorder traversal (Left —+ Root —+ Right)
Constraints:
Number of nodes (employees) <= 10^5
Employee names <= 50 characters.
*/
// Question 14: Employee Hierarchy (Binary Tree)
// Language: C++
// No built-in advanced tree library used – manual binary tree implementation

#include <iostream>
#include <cstring>
using namespace std;
struct Node {
    char name[51];  
    Node* left;
    Node* right;
};
class EmployeeTree {
private:
    Node* root;
    Node* createNode(const char empName[]) {
        Node* newNode = new Node;
        strcpy(newNode->name, empName);
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->name << " ";
        inorder(node->right);
    }

public:
    EmployeeTree() {
        root = nullptr;
    }
    void insertRoot(const char empName[]) {
        if (root != nullptr) {
            cout << "Root already exists!\n";
            return;
        }
        root = createNode(empName);
    }

    void insertLeft(Node* parent, const char empName[]) {
        if (parent->left != nullptr) {
            cout << "Left child already exists for " << parent->name << "\n";
            return;
        }
        parent->left = createNode(empName);
    }

    void insertRight(Node* parent, const char empName[]) {
        if (parent->right != nullptr) {
            cout << "Right child already exists for " << parent->name << "\n";
            return;
        }
        parent->right = createNode(empName);
    }

    Node* getRoot() {
        return root;
    }

    void displayInorder() {
        if (root == nullptr) {
            cout << "[No employees in hierarchy]\n";
            return;
        }
        cout << "Inorder traversal of employees: ";
        inorder(root);
        cout << "\n";
    }
};

int main() {
    EmployeeTree company;
    char name[51];
    cout << "Enter name of CEO: ";
    cin.getline(name, 51);
    company.insertRoot(name);
    cout << "Enter name of left employee under CEO: ";
    cin.getline(name, 51);
    company.insertLeft(company.getRoot(), name);
    cout << "Enter name of right employee under CEO: ";
    cin.getline(name, 51);
    company.insertRight(company.getRoot(), name);
    cout << "Enter name of left employee under " << company.getRoot()->left->name << ": ";
    cin.getline(name, 51);
    company.insertLeft(company.getRoot()->left, name);
    company.displayInorder();

    return 0;
}

/*
Approach:
We created a manual binary tree structure where each node stores an employee name.
The tree is built interactively by linking nodes as left or right children.
Inorder traversal visits left subtree, root, then right subtree.
This approach works well for representing a small company's employee hierarchy.
*/
