#include<iostream>
using namespace std;


struct LinkNode
{
    int data;
    LinkNode* next;
    LinkNode():next(nullptr){}
    //LinkNode(int d):data(d),next(nullptr){}
    LinkNode(int val)
    {
        this->data=val;
        this->next=nullptr;
    }
};

class Stack
{
public:
    LinkNode* head;
    int size=0;
    Stack():head(nullptr){}

    void push(int val)
    {
        if(size==20)
        {
            cout<<"999"<<endl;
            return;
        } 
        LinkNode* p=new LinkNode(val);
        p->next=head;
        head=p;
        size++;
    }

    bool isEmpty()
    {
        if(head==nullptr) return true;
        else return false;
    }

    void pop()
    {
        //if(isEmpty()) return;
        LinkNode* p=head;
        head=p->next;
        delete p;
        size--;            
    }

    int top()
    {
        return head->data;
    }
};