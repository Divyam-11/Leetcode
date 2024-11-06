class Solution
{
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        else if (!subRoot || !root)
            return false;

        if (isSameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};