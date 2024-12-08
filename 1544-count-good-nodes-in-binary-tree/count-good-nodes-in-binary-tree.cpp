class Solution
{
    int count = 0;
    void helper(TreeNode *root, int max_value)
    {
        if (!root)
            return;
        if(root->val >= max_value){
            count++;
            max_value = root->val;
        }
        helper(root->left,max_value);
        helper(root->right,max_value);
    }

public:
    int goodNodes(TreeNode *root)
    {
        if(!root) return 0;
        helper(root,INT_MIN);
        return count;
    }
};