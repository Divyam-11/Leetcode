class Solution
{
public:
    bool solve(ListNode *head, TreeNode *root, ListNode *goat)
    {
        if (!head)
            return true;
        if (!root)
            return false;
        if (root->val != head->val)
            return false;
        return solve(head->next, root->left, goat) || solve(head->next, root->right, goat);
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root)
            return false;

        return solve(head, root, nullptr) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};