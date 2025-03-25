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

int main()
{
    int n;
    Node* head = NULL;
    Node* cur = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        Node* s = new Node(temp);
        if (head == NULL)
        {
            head = s;
            cur = head;
        }

        else
        {
            cur->next = s;
            cur = cur->next;
        }
}
