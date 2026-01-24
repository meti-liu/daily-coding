

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool mirror(TreeNode* left,TreeNode* right)
    {
        if(left==nullptr&&right==nullptr) return true;
        if(left!=nullptr&&right==nullptr) return false;
        if(right!=nullptr&&left==nullptr) return false;
        if(left->val!=right->val) return false;
        else return mirror(left->right,right->left)&& mirror(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root==nullptr) return true;
        else return mirror(root->left,root->right);
    }
};