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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        
        ListNode* dummy = new ListNode(0, head);
        
        // 1) reach node at position "left"
        ListNode* leftPrev = dummy;
        ListNode* cur = head;
        for (int i = 0; i < left - 1; ++i) {
            leftPrev = cur;
            cur = cur->next;
        }

        // Now cur="left", leftPrev="node before left"
        // 2) reverse from left to right
        ListNode* prev = nullptr;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* tmpNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmpNext;
        }

        // 3) Update pointers
        leftPrev->next->next = cur;  // cur is node after "right"
        leftPrev->next = prev;       // prev is "right"
        
        return dummy->next;
    }
};
