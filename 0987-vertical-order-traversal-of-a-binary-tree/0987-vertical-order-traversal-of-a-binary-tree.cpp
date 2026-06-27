class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> mpp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front().first;
                int val = q.front().second;
                mpp[val][level].push_back(node->val);
                // cout<<val<<" "<<level<<" "<<node->val<<endl;
                q.pop();
                if (node->left)
                {
                    q.push({node->left, val - 1});
                }
                if (node->right)
                {
                    q.push({node->right, val + 1});
                }
            }
            level++;
        }
        vector<vector<int>> result;
        for (auto i : mpp)
        {
            vector<int> temp;
            for (auto j : i.second)
            {
                
                sort(j.second.begin(), j.second.end());
                for (auto k : j.second)
                {
                    // cout<<i.first<<" "<<j.first<<" "<<k<<endl;
                    temp.push_back(k);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};