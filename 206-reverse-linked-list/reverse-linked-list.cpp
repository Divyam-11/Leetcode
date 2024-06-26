/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

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
};