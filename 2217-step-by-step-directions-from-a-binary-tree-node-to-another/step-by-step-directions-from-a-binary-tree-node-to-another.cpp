class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
    {
        if (root == NULL || root->val == p || root->val == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
            return root;
    }
    string getPath(TreeNode *root, int target, string &temp)
    {
        if (!root)
            return "";

        if (root->val == target)
            return temp;

        temp.push_back('L');
        string left = getPath(root->left, target, temp);
        temp.pop_back();

        if (!left.empty())
            return left;

        temp.push_back('R');
        string right = getPath(root->right, target, temp);
        temp.pop_back();

        return right;
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *lcs = lowestCommonAncestor(root, startValue, destValue);
        if (lcs->val == startValue)
        {
            string temp;
            return getPath(lcs, destValue, temp);
        }
        else if (lcs->val == destValue)
        {
            string temp;
            string path = getPath(lcs, startValue, temp);
            return string(path.size(), 'U');
        }
        else
        {
            string temp;
            string left = getPath(lcs, startValue, temp);
            temp.clear();
            string right = getPath(lcs, destValue, temp);
            string res = string(left.size(), 'U') + right;
            return res;
        }
    }
};