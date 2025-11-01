class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *res = dummy;
        while (dummy && dummy->next)
        {
            while (dummy->next && mp[dummy->next->val])
            {
                dummy->next = dummy->next->next;
            }
            dummy = dummy->next;
        }
        return res->next;
    }
};