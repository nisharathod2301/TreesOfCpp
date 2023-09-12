#include <iostream>
#include <queue>

using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from user input in level order
TreeNode* buildTree() {
    int rootData;
    cout << "Enter the root value: ";
    cin >> rootData;
    if (rootData == -1) {
        return nullptr; // -1 represents a null node
    }

    TreeNode* root = new TreeNode(rootData);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter left child value of " << current->data << " (-1 for null): ";
        cin >> leftData;

        if (leftData != -1) {
            current->left = new TreeNode(leftData);
            q.push(current->left);
        }

        cout << "Enter right child value of " << current->data << " (-1 for null): ";
        cin >> rightData;

        if (rightData != -1) {
            current->right = new TreeNode(rightData);
            q.push(current->right);
        }
    }

    return root;
}

// Function to perform a level order traversal and print the tree
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }
    }
}

int main() {
    TreeNode* root = buildTree();

    cout << "Level Order Traversal of the Binary Tree: ";
    levelOrderTraversal(root);
    cout << endl;

    // Clean up memory by deleting the tree nodes
    // (you can also write a separate function to do this)
    // For simplicity, we are not including it in this example.

    return 0;
}
