//先序线索二叉树，先序遍历

#include <iostream>

struct BthNode {
    char data;
    BthNode* lchild;
    BthNode* rchild;
    int ltag, rtag;

    BthNode(char d) 
    {
        data = d;
        lchild = rchild = nullptr;
        ltag = rtag = 0;
    }
};

void PreorderThread(BthNode* &p, BthNode* &pre) {
    if (p != nullptr) {
        if (p->lchild == nullptr) //p无左子树
        {
            p->lchild = pre;//p前驱是pre
            p->ltag = 1;//p无左子树
        }

        if (pre != nullptr && pre->rchild == nullptr) //p无右子树
        {
            pre->rchild = p;//pre后继是p
            pre->rtag = 1;//pre没有右子树
        }

        pre = p;

        if (p->ltag == 0) PreorderThread(p->lchild, pre);//有子树时，线索递归子树
        if (p->rtag == 0) PreorderThread(p->rchild, pre);
    }
}

class ThreadTree {
public:
    BthNode* root;
    BthNode* pre;

    ThreadTree() : root(nullptr), pre(nullptr) {}

    void CreatePreorderThread() 
    {
        pre = nullptr;
        PreorderThread(root, pre);

        if (pre != nullptr) 
        {
            pre->rchild = nullptr;
            pre->rtag = 1;
        }
    }
};

// 先序遍历线索二叉树
void PreorderTraversal(BthNode* root) {
    BthNode* p = root;
    while (p != nullptr) {
        std::cout << p->data << " ";

        if (p->ltag == 0)p = p->lchild;//如果ltag=1，lchild是前驱，不符合遍历原则
        else p = p->rchild;//无论rtag是否为0，都会进入rchild（真孩子或后继）
    }
}

// // 测试
// int main() {
//     ThreadTree tree;

//     // 构造一棵示例二叉树
//     tree.root = new BthNode('A');
//     tree.root->lchild = new BthNode('B');
//     tree.root->rchild = new BthNode('C');
//     tree.root->lchild->lchild = new BthNode('D');
//     tree.root->lchild->rchild = new BthNode('E');
//     tree.root->rchild->rchild = new BthNode('F');

//     // 先序线索化
//     tree.CreatePreorderThread();

//     // 先序遍历线索二叉树
//     std::cout << "Preorder Traversal of Threaded Binary Tree: ";
//     PreorderTraversal(tree.root);
//     std::cout << std::endl;

//     return 0;
// }
