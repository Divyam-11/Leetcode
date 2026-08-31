class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        int minDistance = INT_MAX;
        int firstCrit = -1;
        int lastCrit = -1;
        int idx = 1;
        while (fast->next != nullptr)
        {   
            if (fast->val > fast->next->val && fast->val > slow->val)
            {
                if (firstCrit == -1)
                {
                    firstCrit = idx;
                    lastCrit = idx;
                }
                else
                {
                    minDistance = min(minDistance, idx - lastCrit);
                    lastCrit = idx;
                }
            }
            else if (fast->val < fast->next->val && fast->val < slow->val)
            {
                if (firstCrit == -1)
                {
                    firstCrit = idx;
                    lastCrit = idx;
                }
                else
                {
                    minDistance = min(minDistance, idx - lastCrit);
                    lastCrit = idx;
                }
            }
            idx++;
            fast = fast->next;
            slow = slow->next;
           
        }
        if(firstCrit == -1 || lastCrit == firstCrit || minDistance == INT_MAX) return {-1,-1};
        return {minDistance, lastCrit - firstCrit};
    }
};