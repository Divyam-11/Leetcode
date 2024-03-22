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
ListNode* reverseList(ListNode* head) {
    ListNode* prev,*current,*next;
    prev = NULL;
    current = head;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
    }
ListNode* middleNode(ListNode* head) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    // Traverse the list with two pointers, one moving at half the speed of the other
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;        // Move slow pointer by one step
        fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
    }

    // At this point, the slowPtr is at the middle (or one of the middle) node(s)
    return slowPtr;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true; // Empty list or single node is a palindrome

    ListNode* new_head = head;
    ListNode* rev_head = middleNode(new_head);
    new_head = reverseList(rev_head);
    
    while (new_head != nullptr && head != nullptr){
        if (new_head->val != head->val)
            return false;
        new_head = new_head->next;
        head = head->next;
    }
    return true;
}


};