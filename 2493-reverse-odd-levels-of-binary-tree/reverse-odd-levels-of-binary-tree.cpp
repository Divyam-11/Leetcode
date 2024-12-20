class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool reversed = false;
        while (!q.empty())
        {
            vector<TreeNode *> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                level.push_back(temp);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            if (reversed)
            {
                for (int i = 0; i < level.size() / 2; i++)
                {
                    swap(level[i]->val, level[level.size() - 1 - i]->val);
                }
            }
            reversed = !reversed;
        }
        return root;
    }
};