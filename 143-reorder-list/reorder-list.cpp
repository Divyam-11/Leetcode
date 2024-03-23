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
    ListNode* reverse(ListNode *head){
        ListNode* p = NULL , *q = NULL, *r = head;
        while(r!= NULL){
            p = q;
            q = r;
            r = r -> next;

            q -> next = p;
        }
        return q;
    }
    void reorderList(ListNode* head) {
        // Logic - reverse LL after middle node
        // then take 1-1 node from both halves

        if(head == NULL || head -> next == NULL){
            return ;
        }

        ListNode* f = head -> next, *s = head;
        while(f != NULL ){
            f = f->next;
            if(f != NULL){
                f = f->next;
                s = s->next;
            }
        }

        ListNode * second = reverse(s->next);
        ListNode * first = head;
        s->next = NULL;

        // insert even node then odd node one by one
        ListNode *ansHead = new ListNode(-1);
        ListNode * ansTail = ansHead;

        while(first && second){
            //first add even
            ansTail->next = first;
            ansTail = first;
            first = first->next;

            // add odd
            ansTail->next = second;
            ansTail = second;
            second = second->next;
        }

        // in odd case LL -> first has 1 node left
        if(first != NULL){
            ansTail->next = first;
            ansTail = first;
        }


        head = ansHead->next;
    }
};