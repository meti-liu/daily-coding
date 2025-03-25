#include<iostream>
using namespace std;
struct Node
{
    char val;
    Node* next;
    Node(char a)
    {
        this->val=a;
        this->next=nullptr;
    }
};
Node* merge(Node* head1,Node* head2,Node* head3)
{
    Node* dummy=new Node(0);
    dummy->next=head1;
    Node* cur=head1;
    while(cur->next!=nullptr) cur=cur->next;
    cur->next=head2;
    while(cur->next!=nullptr) cur=cur->next;
    cur->next=head3;
    return dummy->next;
}
int main()
{
    Node* h1
}