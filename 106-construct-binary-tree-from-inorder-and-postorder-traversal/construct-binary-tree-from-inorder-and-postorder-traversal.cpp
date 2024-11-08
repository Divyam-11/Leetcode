class Solution
{
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int &root_index)
    {
        if (inorder.empty() || root_index < 0)
            return NULL;
        int node = postorder[root_index];
        root_index--;
        int inorder_root_index = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == node)
            {
                inorder_root_index = i;
                break;
            }
        }
        vector<int> left_inorder(inorder.begin(), inorder.begin() + inorder_root_index);
        vector<int> right_inorder(inorder.begin() + inorder_root_index + 1, inorder.end());
        TreeNode *root = new TreeNode(node);
        root->right = helper(right_inorder, postorder, root_index);
        root->left = helper(left_inorder, postorder, root_index);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int root_index = postorder.size()-1;
        return helper(inorder, postorder,root_index);
    }
};