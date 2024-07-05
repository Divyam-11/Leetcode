class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(-300);
        dummy->next = head;
        bool has = false;
        ListNode * slow = dummy;
        ListNode * fast = dummy->next;
        while(fast){
            if(fast->next != nullptr && fast->next->val == fast->val){
            while(fast->next != nullptr && fast->next->val == fast->val){
                fast = fast->next;
                
                
            }
            slow->next = fast->next;
            }
            else slow = slow->next;




            
            fast = fast->next;
        }
        return dummy->next;
    }
};