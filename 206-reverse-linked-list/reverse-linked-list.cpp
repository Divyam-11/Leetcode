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
class Solution
{
public:
    ListNode * reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *first, *second, *third;
        first = NULL;
        second = head;
        while (second)
        {
            third = second->next;
            second->next = first;
            first = second;
            second = third;
        }
        return first;
    }
};