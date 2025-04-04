class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (!root)
            return nullptr;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (left == right)
            return root;
        else if (left > right)
            return lcaDeepestLeaves(root->left);
        else
            return lcaDeepestLeaves(root->right);

        return nullptr;
    }
};