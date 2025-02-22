class Solution
{
public:
    TreeNode *build(queue<pair<int, int>> &mp, int depth)
    {
        if (depth != mp.front().second)
            return nullptr;
        TreeNode *root = new TreeNode(mp.front().first);
        mp.pop();
        root->left = build(mp, depth + 1);
        root->right = build(mp, depth + 1);
        return root;
    }
    TreeNode *recoverFromPreorder(string traversal)
    {
        queue<pair<int, int>> mp;
        int depth = 0;
        for (int i = 0; i < traversal.size(); i++)
        {
            if (traversal[i] != '-')
            {
                string num;
                while (traversal[i] != '-' && i< traversal.size())
                {
                    num.push_back(traversal[i]);
                    i++;
                }
                i--;

                cout << num << " " << depth << endl;
                mp.push({stoi(num), depth});
                depth = 0;
            }
            else
                depth++;
        }
        return build(mp, 0);
    }
};