class Solution
{
public:
    bool res;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1)
            res = false;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        res = true;
        height(root);
        return res;
    }
};