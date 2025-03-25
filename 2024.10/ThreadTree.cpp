struct BthNode
{
    char data;
    BthNode* lchild;
    BthNode* rchild;
    int ltag,rtag;
    BthNode(char d)
    {
        data=d;
        ltag=rtag=0;
        lchild=rchild=nullptr;
    }
};


class ThreadTree
{
    BthNode* r;//二叉树根
    BthNode* root;//线索树根
    BthNode* pre;

    void Order();
    void CreateThread();
}






void Thread(BthNode* &p)
{
    if(p!=nullptr)
    {
        Thread(p->lchild);//左子树线索化
        if(p->lchild==nullptr)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        else p->ltag=0;



        if(pre->rchild==nullptr)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        else pre->rtag=0;
        pre=p;

        Thread(p->rchild);
    }
}



void Order()//遍历，从最左开始
{
    BthNode* p=root->lchild;
}