#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* createBtree(string str)//括号表达式来生成树
{
    TreeNode* p=nullptr;
    stack<TreeNode*> st;
    bool flag;//true->left false->right
    int i=0;

    TreeNode* root=nullptr;

    while(i<str.length())
    {
        switch (str[i])
        {
        case '('://左括号前的p节点存在孩子节点，入
            flag=true;
            st.push(p);
            i++;
            break;
        case ')'://p的孩子节点已处理完成，弹
            if(!st.empty())//请注意，这个点很重要
            {
                st.pop();
                i++; 
            }
            break;
        case ','://左进右
            flag=false;
            i++;
            break;

        default://此时str[i]就只可能是数据val了
            int num=0;
            while(isdigit(str[i]))
            {
                num=10*num+(str[i]-'0');
                i++;
            }
            p=new TreeNode(num);
            if(root==nullptr) root=p;
            if(flag==true&&!st.empty()) st.top()->left=p; 
            if(flag==false&&!st.empty()) st.top()->right=p;
            break;
        }
    }
    return root;
}

void preOrder(TreeNode* root)//前序遍历
{
    if(root==nullptr) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    string str;
    getline(cin, str); // 输入括号表达式字符串
    TreeNode* root = createBtree(str);
    preOrder(root); // 前序遍历输出
    return 0;
}
