class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode * one, * two, * three;
        one = dummy;
        two = dummy->next;
        three = dummy->next->next;
        while (three)
        {
            one->next = three;
            two->next = three->next;
            three->next = two;
            three = two;
            if(three->next){
            one = three;
            two = one->next;
            three = two->next;
            }
            else break;


        }
        
    return dummy->next;
    }
};