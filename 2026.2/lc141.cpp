
struct ListNode 
{
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==nullptr||head->next==nullptr) return false;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(slow!=fast)
        {
            if(fast==nullptr||fast->next==nullptr) return false;//由于短路原则，这两个npt的判断顺序不能调换，否则出现空指针问题
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};