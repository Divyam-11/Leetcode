class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) return head;
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){

        

            while (!st.empty() && st.top()->val < temp->val)
            {
            st.pop();
            }
            

        st.push(temp);
        temp = temp->next;
        }
        ListNode* chain = nullptr;

        while (!st.empty())
        {
        temp = st.top();
        st.pop();
        temp->next = chain;
        chain = temp;
        }
        return chain;
        
        


    }
};