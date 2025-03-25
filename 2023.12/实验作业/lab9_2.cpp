#include <iostream>

// 链表节点的结构
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// 栈类
class Stack {
private:
    Node* top;  // 栈顶元素

public:
    Stack() : top(nullptr) {}

    // 入栈操作
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // 出栈操作
    int pop() {
        if (top == nullptr) return -1; // 栈为空
        Node* temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    // 检查栈是否为空
    bool isEmpty() {
        return top == nullptr;
    }

    // 析构函数
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    // 入栈5个元素
    for (int i = 1; i <= 5; ++i) {
        s.push(i);
    }
    // 出栈并显示
    while (!s.isEmpty()) {
        std::cout << s.pop() << " ";
    }
    return 0;
}
