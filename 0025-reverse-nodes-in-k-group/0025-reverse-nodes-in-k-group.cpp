class Solution
{
public:
    ListNode *revereseK(ListNode *p1, ListNode *p2, int k)
    {
        ListNode *prev = p2;
        ListNode *curr = p1;
        while (k--)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
        int epochs = len / k;
        if (epochs == 0)
            return head;
        ListNode *p1 = dummy;
        ListNode *p2 = dummy;
        for (int i = 0; i <= k; i++)
        {
            p2 = p2->next;
        }
        for (int i = 0; i < epochs; i++)
        {
            p1->next = revereseK(p1->next, p2, k);
            if (i == epochs - 1)
                break;
            for (int i = 0; i < k; i++)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};