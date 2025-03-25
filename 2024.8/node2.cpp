#include<iostream>
using namespace std;
class LNode
{
public:
    int data;
    LNode *next;

    LNode(int val)
    {
        this->data=val;
        this->next=nullptr;
    }
};
int main()
{
    LNode *head,*middle,*last;
    head=new LNode(10);
    middle=new LNode(20);
    last=new LNode(30);

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

