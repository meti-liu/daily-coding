#include<iostream>
using namespace std;
struct TreeNode 
{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* CreateTree(char a[],int index,int n)
{
    if(index>=n) return nullptr;
    TreeNode* root=new TreeNode(a[index]);
    root->left=CreateTree(a,2*index+1,n);
    root->right=CreateTree(a,2*index+2,n);
    return root;
}

void dfs(TreeNode* root)
{
    if(!root) return;
    if(root->val=='#') return;
    else
    {
        cout<<root->val<<endl;
        dfs(root->left);
        dfs(root->right);
    }
    cout<<"No exist descendants";
}

TreeNode* Find(TreeNode* root,char c)
{
    if(!root) return nullptr;
    if(c==root->val) return root;
    else
    {
        Find(root->left,c);
        Find(root->right,c);
    }
    cout<<"No exist Node";
    return root;
}

int main()
{
    char a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    TreeNode* tree=CreateTree(a,0,n);
    char k;
    cin>>k;
    dfs(Find(tree,k));
    return 0;
}