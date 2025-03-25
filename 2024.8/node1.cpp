#include<iostream>
using namespace std;
struct LNode
{
    int data;
    struct LNode *next;
};
int main()
{
    LNode *head,*middle,*last;
    head=new LNode();
    middle=new LNode();
    last=new LNode();

    head->data=10;
    middle->data=20;
    last->data=30;

    head->next=middle;
    middle->next=last;
    last->next=nullptr;

    LNode *current=head;
    while(current!=nullptr)
    {
        cout<<current->data<<endl;
        current=current->next;
    }
    
}