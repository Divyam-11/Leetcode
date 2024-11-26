class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;
        ListNode *temp =head;
        int length = 0;
        while (temp)
        {
            length++;
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        temp = dummy;
        ListNode* temp2 = dummy->next;
        int m = length - n;
        for (int i = 0; i < length - n; i++)
        {
            temp = temp->next;
            temp2 = temp2->next;
            cout<<temp->val<<endl;
        
        
        }
        
        temp->next = temp2->next;
        delete temp2;
        
        
        return dummy->next;
    }
};