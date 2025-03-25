#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){}
};


int height(TreeNode* root)
{
    if(root==nullptr) return 0;
    int leftH=height(root->left);
    int rightH=height(root->right);
    return max(leftH,rightH)+1;
}


bool balance(TreeNode* root)
{
    if(root==nullptr) return true;
    int k=height(root->left)-height(root->right);
    if(abs(k)>1) return false;
    return balance(root->left)&&balance(root->right);
}




TreeNode* buildTree(const vector<string>& nodes, int index) 
{
    if (index >= nodes.size() || nodes[index] == "null") return nullptr;
    
    // 创建当前节点
    TreeNode* node = new TreeNode(stoi(nodes[index]));
    
    // 递归构建左子树和右子树
    node->left = buildTree(nodes, 2 * index + 1);
    node->right = buildTree(nodes, 2 * index + 2);
    
    return node;
}


int main()
{
    ifstream ifs("in.txt");
    ofstream ofs("out.txt");
    string line;
    getline(cin,line);
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while(ss>>token) tokens.push_back(token);

    if(tokens[0]=="null")
    {
       ofs<<"True";
        return 0;
    } 

    TreeNode* root=buildTree(tokens,0);
    if(balance(root)==true) cout<<"True";
    else cout<<"False";
    return 0;
}