class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* first ;
        ListNode* second;
        int count = 0;
        while(temp){
            if(count == a-1){
                first = temp;

            }
            else if(count == b){
                second = temp;
                break;
            }
            temp = temp->next;
            count++;
        }
        first->next = list2;
        temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = second->next;
        return list1;
    }
};