#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};



ListNode* Middle(ListNode* head)//向上取整
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=nullptr&&fast->next->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}