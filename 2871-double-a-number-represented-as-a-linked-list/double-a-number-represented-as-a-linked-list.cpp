class Solution {
private:
ListNode* reverseList(ListNode* head){
    if(!head) return head;
    ListNode* first = nullptr;
    ListNode* second = head;
    ListNode* third = head->next;
    while(second){
        second->next = first;
        first = second ; 
        second = third;
        if (third) third = third->next;
    }
    return first;
}
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode* temp = head;
        ListNode* slow;
        while(temp){
            int num = temp->val;
            num+=num;
            temp->val = num%10 + carry;
            carry = num/10;
            slow = temp;
            temp = temp->next;


        }
    if(carry != 0 ){
        slow->next = new ListNode(carry);
        
    }
    head = reverseList(head);
    return head;
    }
};