class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
ListNode* odd = head;
ListNode* even = head->next;
ListNode* even_start = even;
while (odd->next && even->next)
{
odd->next = odd->next->next;
even->next = even->next->next;
odd = odd->next;
even = even->next;

}
odd->next = even_start;
return head;


    }
};