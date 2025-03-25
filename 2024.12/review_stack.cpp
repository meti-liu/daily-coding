#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int n){this->data=n;this->next=nullptr;}
    Node(){this->next=nullptr;}
};
class Stack
{
public:
    Node* head;
    Stack()
    {
        this->head=nullptr;
    }
    bool isEmpty()
    {
        if(head==nullptr) return true;
        else return false;
    }
    int top()
    {
        if(!isEmpty()) return head->data;
    }
    void push(int n)
    {
        Node* s=new Node(n);
        s->next=head;
        head=s;
    }
    void pop()
    {
        if(!isEmpty())
        {
            Node* s=head;
            head=head->next;
            delete s;
        }
    }
    void print()
    {
        if(isEmpty()) cout<<"this stack is empty"<<endl;
        else
        {
            Node* cur=head;
            while(cur!=nullptr)
            {
                cout<<cur->data<<" ";
                cur=cur->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    Stack stack;

    // 入栈操作
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // 打印栈内容
    stack.print();  // Output: 30 20 10

    // 查看栈顶元素
    cout << "Top element: " << stack.top() << endl;  // Output: 30

    // 出栈操作
    stack.pop();
    stack.print();  // Output: 20 10

    // 出栈操作
    stack.pop();
    stack.print();  // Output: 10

    // 出栈操作
    stack.pop();
    stack.print();  // Output: Stack is empty.

    return 0;
}