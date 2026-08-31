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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical_point;
        ListNode * slow = head;
        ListNode * fast = head->next;
        int index = 1;
        while (fast->next)
        {   
            if(fast->val < fast->next->val && fast->val < slow->val){
                critical_point.push_back(index);
            }
            else if(fast->val > fast->next->val && fast->val > slow->val){
                critical_point.push_back(index);
            }
            index++;
            slow = slow->next;
            fast = fast->next;
        }
    int min_distance = INT_MAX;
    int max_distance = -1;
    if(critical_point.size() < 2) return {-1,-1};
    for(int i = 1 ; i < critical_point.size();i++){
        int dis = critical_point[i] - critical_point[i-1];
        min_distance = min(min_distance,dis);
        max_distance = max(max_distance,dis);
    }
    
    return {min_distance,critical_point.back() - critical_point[0]};
    }
};