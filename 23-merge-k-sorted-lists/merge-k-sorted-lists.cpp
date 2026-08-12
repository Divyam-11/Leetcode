
class Compare
{ public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        ListNode *dummy = new ListNode(67);
        ListNode *head = dummy;
        for (int i = 0; i < lists.size(); i++)
        {   
            if(lists[i])
            pq.push(lists[i]);
        }
        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();
            head->next = temp;
            head = head->next;
            if (temp->next)
            {
                temp = temp->next;
                pq.push(temp);
            }
            
            
        }
        return dummy->next;
    }
};