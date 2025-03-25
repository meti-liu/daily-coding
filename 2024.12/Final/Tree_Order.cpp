#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";  // 访问根节点
    preOrder(root->left);      // 遍历左子树
    preOrder(root->right);     // 遍历右子树
}

// 中序遍历
void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);       // 遍历左子树
    cout << root->val << " ";  // 访问根节点
    inOrder(root->right);      // 遍历右子树
}

// 后序遍历
void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);     // 遍历左子树
    postOrder(root->right);    // 遍历右子树
    cout << root->val << " ";  // 访问根节点
}

int main() {
    // 构造示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 测试遍历方法
    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;

    cout << "In-order: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order: ";
    postOrder(root);
    cout << endl;

    return 0;
}
