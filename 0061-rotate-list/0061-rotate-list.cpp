class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode *temp = head;
        int len = 1;
        while (temp->next)
        {
            len++;
            temp = temp->next;
            
        }
        temp->next = head;
        k = k % len;
        int steps = len - k;
        // cout<<len<<" "<<steps<<k<<endl;
        for (int i = 0; i < steps; i++)
        {
            temp = temp->next;
        }
        ListNode* goat = temp->next;
        temp->next = nullptr;
        return goat;
    }
};