#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const vector<int>& arr, int index) {
    if (index >= arr.size() || arr[index] == -1) return nullptr; // -1 表示空节点
    TreeNode* root = new TreeNode(arr[index]);
    root->left = createTree(arr, 2 * index + 1);
    root->right = createTree(arr, 2 * index + 2);
    return root;
}

// 打印树前序遍历用于测试
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, -1, 7}; // -1 表示空节点
    TreeNode* root = createTree(arr, 0);
    cout << "Pre-order: ";
    preOrder(root);
    return 0;
}
