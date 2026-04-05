class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node != nullptr)
                {
                    s += to_string(node->val) + ',';
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    s.push_back('*');
                    s.push_back(',');
                }
            }
            s.push_back(';');
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<vector<string>> mat;
        vector<string> temp;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != ';')
            {
                string num;
                while (data[i] != ',')
                {
                    num.push_back(data[i]);
                    i++;
                }
                temp.push_back(num);
            }
            else
            {
                mat.push_back(temp);
                temp.clear();
            }
        }
        vector<vector<TreeNode *>> build(mat.size());
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == "*")
                {
                    build[i].push_back(nullptr);
                }
                else
                {
                    build[i].push_back(new TreeNode(stoi(mat[i][j])));
                }
            }
        }
        for (int i = 0; i < build.size() - 1; i++)
        {
            int j = 0;
            int k = 0;
            while (j < build[i].size())
            {
                while (j < build[i].size() && build[i][j] == nullptr)
                    j++;
                if (j >= build[i].size())
                    break;
                if (k < build[i + 1].size())
                {
                    build[i][j]->left = build[i + 1][k];
                    k++;
                }
                if (k < build[i + 1].size())
                {
                    build[i][j]->right = build[i + 1][k];
                    k++;
                }
                j++;
            }
        }
        return build[0][0];
    }
};