/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long, vector<long>, greater<long>> minH;
        if (root == NULL)
            return -1;
        queue<TreeNode *> q;
        q.push(root);

        
        while (!q.empty())
        {
            
            long long level = 0;
            int s = q.size();

            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level+=node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
            }
            minH.push(level);
        }
        if(minH.size() < k) return -1;
        while(minH.size()>k) minH.pop();
        return minH.top();
    }
};