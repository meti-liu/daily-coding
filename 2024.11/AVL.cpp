#include<iostream>
using namespace std;
int main()
{

}


struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(TreeNode* node) 
{
    if (node == nullptr) return 0;
    return node->height;
}


TreeNode* rightRotate(TreeNode* y) 
{
    // 1. 设置新的根节点 x
    TreeNode* x = y->left;
    // 2. 将 x 的右子树作为 y 的左子树
    y->left = x->right;
    // 3. 将 y 设置为 x 的右子树
    x->right = y;
    
    // 4. 更新节点的高度
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    // 5. 返回新的根节点
    return x;
}


TreeNode* leftRotate(TreeNode* y) 
{
    // 1. 设置新的根节点 x
    TreeNode* x = y->right;
    // 2. 将 x 的右子树作为 y 的左子树
    y->right = x->left;
    // 3. 将 y 设置为 x 的右子树
    x->left = y;
    
    // 4. 更新节点的高度
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    // 5. 返回新的根节点
    return x;
}


TreeNode* LRRotate(TreeNode* node) 
{
    // 首先对 node 的左子节点执行左旋转
    node->left = leftRotate(node->left);
    
    // 然后对 node 执行右旋转
    return rightRotate(node);
}


