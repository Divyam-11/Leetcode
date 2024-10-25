class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        vector<int> level_sum;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            int sum = 0;
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            level_sum.push_back(sum);
        }

        root->val = 0;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int s = q.size();
            int sum = 0;
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                int sibling_sum = 0;
                if (temp->left)
                    sibling_sum += temp->left->val;
                if (temp->right)
                    sibling_sum += temp->right->val;

                if (temp->left)
                {
                    temp->left->val = level_sum[level + 1] - sibling_sum;
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    temp->right->val = level_sum[level + 1] -  sibling_sum;
                    q.push(temp->right);
                }
            }
            level++;
        }
        return root;
    }
};