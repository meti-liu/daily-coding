#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTreeFromString(const string& str) {
    stack<TreeNode*> stk;
    TreeNode* root = nullptr;
    TreeNode* current = nullptr;
    bool isLeft = true; // 标记当前插入左子树还是右子树
    int i = 0;

    while (i < str.size()) {
        if (isdigit(str[i])) {
            int num = 0;
            while (i < str.size() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            TreeNode* newNode = new TreeNode(num);
            if (!root) root = newNode;
            if (current) {
                if (isLeft) current->left = newNode;
                else current->right = newNode;
            }
            current = newNode;
        } else if (str[i] == '(') {
            stk.push(current);
            isLeft = true;
            i++;
        } else if (str[i] == ')') {
            stk.pop();
            i++;
        } else if (str[i] == ',') {
            isLeft = false;
            i++;
        } else {
            i++;
        }
    }
    return root;
}

void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    string str = "1(2(4,5),3(,7))";
    TreeNode* root = createTreeFromString(str);
    cout << "Pre-order: ";
    preOrder(root);
    return 0;
}
