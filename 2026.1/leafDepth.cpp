#include<iostream>
#include<vector>
using namespace std;
struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int MaxDepth(TreeNode* root)
{
    if(!root) return 0;
    if(root->left==nullptr&&root->right==nullptr) return 1;
    else return max(MaxDepth(root->left),MaxDepth(root->right))+1;
}



void dfs(int Depth,TreeNode* root,int MaxDepth,vector<TreeNode*>& leaves)
{
    if(!root) return;
    if(root->left==nullptr&&root->right==nullptr)
    {
        if(Depth==MaxDepth) leaves.push_back(root);
    }

    dfs(Depth+1,root->left,MaxDepth,leaves);
    dfs(Depth+1,root->right,MaxDepth,leaves);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->left->right->left = new TreeNode(8);

    // 计算最大深度
    int maxDepth = MaxDepth(root);

    // 查找所有最深的叶子节点
    vector<TreeNode*> deepestLeaves;
    dfs(1, root, maxDepth, deepestLeaves);

    // 输出所有最深的叶子节点的值
    if (!deepestLeaves.empty()) {
        cout << "最深的叶子节点的值是: ";
        for (const auto& node : deepestLeaves) {
            cout << node->val << " ";
        }
        cout << endl;
    } 

    return 0;
}