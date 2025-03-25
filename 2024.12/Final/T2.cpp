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
    if(index>=n||a[index]=='#') return nullptr;
    TreeNode* root=new TreeNode(a[index]);
    root->left=CreateTree(a,2*index+1,n);
    root->right=CreateTree(a,2*index+2,n);
    return root;
}

void dfs(TreeNode* root)
{
    if(!root) return;
    if(root->val=='#') return;
    if(root->left->val=='#'&&root->right->val=='#')
    {
        cout<<"No exist descendants";
        return;
    }
    if(root->left->val!='#')
    {
        cout<<root->left->val;
        dfs(root->left);
    }
    if(root->right->val!='#')
    {
        cout<<root->right->val;
        dfs(root->right);
    } 
}

bool Find(TreeNode* root,char c)
{
    if(!root) return false;
    if(c==root->val) return true;
    else
    {
        Find(root->left,c);
        Find(root->right,c);
    }
    return false;
}

void print(TreeNode* root)
{
    if(!root) return;
    else cout<<endl<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    char a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    TreeNode* tree=CreateTree(a,0,n);
    // char k;
    // cin>>k;
    // if(Find(tree,k)) dfs(tree);
    // else cout<<"Node does not exist";
    print(tree);
    return 0;
}