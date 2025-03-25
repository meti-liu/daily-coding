#include <iostream>
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


// 判断括号是否匹配
bool isValid(string s) 
{
    Stack stack;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') stack.push(ch); // 左括号入栈

        else 
        {
            if (stack.isEmpty()) return false; // 栈为空，右括号无匹配

            char top = stack.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                stack.pop(); // 匹配成功，出栈
            } 
            else return false; // 不匹配
        }
    }

    return stack.isEmpty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
