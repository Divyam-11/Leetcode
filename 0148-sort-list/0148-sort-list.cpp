class Solution
{
public:
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(67);
        ListNode *head = dummy;
        while (left && right)
        {
            if (left->val <= right->val)
            {
                dummy->next = left;
                dummy = dummy->next;
                left = left->next;
            }
            else
            {
                dummy->next = right;
                dummy = dummy->next;
                right = right->next;
            }
        }
        if (left)
        {
            dummy->next = left;
        }
        if (right)
        {
            dummy->next = right;
        }
        return head->next;
    }
    ListNode *mergeSort(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode *dummy = new ListNode(67);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        // cout<<head->val<<" "<<head2->val<<endl;
        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(head2);
        return merge(left, right);
    }
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};