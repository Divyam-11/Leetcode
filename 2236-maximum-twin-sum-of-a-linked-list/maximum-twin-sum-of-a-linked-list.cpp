class Solution {
    private:
        ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode* first = nullptr;
        ListNode* second = head;
        ListNode* third = head->next;
        while (second) {
            second->next = first;
            first = second;
            second = third;
            if (third)
                third = third->next;
        }
        return first;
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

public:
    int pairSum(ListNode* head) {
        ListNode * temp = head;
    ListNode* mid =  middleNode(temp);
    mid = reverseList(mid);
    int result = -1;
    while(head && mid){
        result = max(result, head->val + mid->val);
        head = head->next;
        mid = mid->next;
    }
    return result;
    }
};