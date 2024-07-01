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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> result;
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }
        int total_div = length/k;
        int div_overflow = length%k;
        temp = head;
        while(temp){
            result.push_back(temp);
            int currlength = 1;
            while(currlength<total_div){
                temp = temp->next;
                currlength++;
            }
            if(div_overflow>0 && length>k){
                temp = temp->next;
                div_overflow--;
            }
            ListNode * x = temp->next;
            temp->next = NULL;
            temp = x;
        }
        while(length<k){
            result.push_back(NULL);
            length++;
        }
        return result;
    }
};