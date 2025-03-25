#include <iostream>

// 链表节点的结构
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// 队列类
class Queue {
private:
    Node* front;  // 队列头部
    Node* rear;   // 队列尾部

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // 入队操作
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // 出队操作
    int dequeue() {
        if (front == nullptr) return -1; // 队列为空
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        int data = temp->data;
        delete temp;
        return data;
    }

    // 检查队列是否为空
    bool isEmpty() {
        return front == nullptr;
    }

    // 析构函数
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    // 入队5个元素
    for (int i = 1; i <= 5; ++i) {
        q.enqueue(i);
    }
    // 出队并显示
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }
    return 0;
}
