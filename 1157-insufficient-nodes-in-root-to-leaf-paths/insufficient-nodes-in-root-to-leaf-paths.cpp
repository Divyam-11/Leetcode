class Solution
{
public:
    TreeNode *dfs(TreeNode *root, int sum, int limit)
    {
        if (!root)
            return nullptr;
        sum += root->val;
        if (!root->left && !root->right)
        {
            return (sum >= limit) ? root : nullptr;
        }
        root->left = dfs(root->left, sum, limit);
        root->right = dfs(root->right, sum, limit);
        if (!root->left && !root->right)
            return nullptr;
        return root;
    }
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        return dfs(root, 0, limit);
    }
};