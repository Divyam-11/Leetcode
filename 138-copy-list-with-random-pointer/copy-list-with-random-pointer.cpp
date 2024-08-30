class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        unordered_map<Node *, Node *> mapping;
        while (temp)
        {
            mapping[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            mapping[temp]->next = mapping[temp->next];
            mapping[temp]->random = mapping[temp->random];
            temp = temp->next;
        }
        return mapping[head];
    }
};