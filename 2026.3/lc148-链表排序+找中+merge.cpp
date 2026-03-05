struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* sortList(ListNode* head) 
    {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* mid=findMiddle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=nullptr;

        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }

    ListNode* findMiddle(ListNode* head) 
    {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;//注意2
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right) 
    {
        ListNode* dummy=new ListNode(0);
        ListNode* current=dummy;

        while(left&&right)//注意1
        {
            if(left->val<right->val)
            {
                current->next=left;
                left=left->next;
            }
            else
            {
                current->next=right;
                right=right->next;
            }
            current=current->next;
        }

        if(left) current->next=left;//归并的核心思路在于，左右两边都是有序的情况下进行合并
        if(right) current->next=right;


        return dummy->next;
    }


};