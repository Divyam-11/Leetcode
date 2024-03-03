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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int count = 0 ;
        while(ptr){
            count++;
            ptr = ptr->next;

        }

        int x = count - n;
       if (x == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* slow = NULL;
        ptr = head;
        int i = 0;
        while(i<x){
            slow = ptr; 
            ptr = ptr->next;
            i++;

        }     
        slow->next = ptr->next;
        delete ptr;
        return head;  
    }
};