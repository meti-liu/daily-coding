#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) 
{
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);
    return root;
}

bool search(TreeNode* root, int key) 
{
    if (!root) return false;
    if (root->val == key) return true;
    else if (key < root->val) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    cout << (search(root, 3) ? "Found" : "Not Found") << endl;
    cout << (search(root, 6) ? "Found" : "Not Found") << endl;
    return 0;
}