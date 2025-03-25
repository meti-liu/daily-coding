#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next=nullptr;
    }
};
class LinkedList
{

public:

    Node* head;
    LinkedList(){this->head=nullptr;}
    LinkedList(Node* head) {this->head=head;}


    void insert(int n)
    {
        Node* s=new Node(n);
        Node* cur=head;
        if(head==nullptr)
        {
            head=s;
            return;
        }
        while(cur->next!=nullptr) cur=cur->next;
        if(head==nullptr)   head=s;
        cur->next=s;
    }

    void print()
    {
        Node* cur=head;
        while(cur!=nullptr)
        {
            cout<<cur->data<<endl;
            cur=cur->next;
        }
    }

};

Node* MergeList(LinkedList &L1,LinkedList &L2)
{
    Node* cur=L1.head;
    while(cur->next!=nullptr) cur=cur->next;
    cur->next=L2.head;
    while(cur->next!=nullptr) cur=cur->next;
    return L1.head;
}
int main()
{
    int n;
    cin>>n;
    LinkedList L;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        L.insert(temp);
    }
    L.print();
    return 0;
}