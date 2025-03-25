#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int n)
    {
        this->data=n;
        this->next=nullptr;
    }
};

Node* insert1(Node *head,int value)//尾插法(但没有维护尾指针)
{
    Node* cur=head;
    Node* s=new Node(value);
    if(head==nullptr)
    {
        head=s;
        return head;
    }
    while(cur->next!=nullptr) cur=cur->next;
    cur->next=s;
    return head;
}

Node* insert2(Node* head,int value)
{
    Node* s=new Node(value);
    s->next=head;
    head=s;
    return head;
}


int length(Node* head)
{
    Node* cur=head;
    int l=0;
    while(cur!=nullptr)
    {
        cur=cur->next;
        l++;
    }
    return l;
}

void print(Node* head)
{
    Node* cur=head;
    while(cur!=nullptr)
    {
        cout<<cur->data;
        cur=cur->next;

    }
}

void split(Node* head,int k1,int k2)
{
    Node* cur=head;
    Node* L1=nullptr;
    Node* L2=nullptr;
    Node* L3=nullptr;
    while(cur!=nullptr)
    {
        Node* s=cur;
        cur=cur->next;
        if(s->data<k1) L1=insert1(L1,s->data);
        else if(s->data>=k1&&s->data<k2) L2=insert1(L2,s->data);
        else if(s->data>=k2) L3=insert1(L3,s->data);


    }
    cout<<length(L1)-1<<" "<<length(L1)+length(L2);
}

int main()
{
    int k1,k2,n;
    cin>>k1>>k2>>n;
    Node* L=nullptr;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        L=insert1(L,p);
    }
    split(L,k1,k2);
    return 0;
}
