#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


TreeNode* insert(TreeNode* root,int val)
{
    if(root==nullptr) return new TreeNode(val);
    if(val<root->val) root->left=insert(root->left,val);
    if(val>=root->val) root->right=insert(root->right,val);//可以用else，若不用则注意取等问题
    return root;
}

TreeNode* maxNode(TreeNode* root)
{
    TreeNode* cur=root;
    while(cur->right!=nullptr) root=root->right;
    return cur;
}



TreeNode* deleteNode(TreeNode* root,int key)
{
    if(root==nullptr) return nullptr;
    if(key<root->val) return deleteNode(root->left,key);
    else if(key>root->val)return deleteNode(root->right,key);

    else//root==key
    {
        //case1
        if(root->left==nullptr&&root->right==nullptr) //叶子
        {
            delete root;
            return nullptr;
        }
        //case2&3
        if(root->left==nullptr&&root->right!=nullptr)
        {
            TreeNode* temp=root->right;
            delete root;
            return temp;//传入的是root，传出的是子树，因此成功实现了用子树代替root的效果
        }
        if(root->left!=nullptr&&root->right==nullptr)
        {
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }
        //case4 递归
        if(root->left!=nullptr&&root->right!=nullptr)
        {
            TreeNode* temp=maxNode(root->left);
            root->val=temp->val;
            root->left=deleteNode(root->left,temp->val);//删除左子树中的最大节点
        }

    }

}
int main()
{

}