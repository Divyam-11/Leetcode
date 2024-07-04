
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int sum = 0;
        while(fast){
            if(fast->val == 0){
                slow->next = fast;
                slow->val = sum;
                slow = fast;
                sum = 0;
            }
        sum+=fast->val;
        if(fast->next == NULL) fast = nullptr;
        else
        fast = fast->next;
        }
        slow = head;
        while (slow->next->next != nullptr)
        {
            slow = slow->next;
        }
        slow->next = nullptr;
        
        return head;
    }
};