class Solution
{

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &root_index)
    {
        if (inorder.empty())
            return NULL;
        int node = preorder[root_index];
        root_index++;
        int inorder_root_index = -1;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (node == inorder[i])
            {
                inorder_root_index = i;
                break;
            }
        }
    vector<int> left_inorder(inorder.begin(), inorder.begin() + inorder_root_index);
        vector<int> right_inorder(inorder.begin() + inorder_root_index + 1, inorder.end());
        TreeNode *root = new TreeNode(node);
        root->left = helper(preorder, left_inorder, root_index);
        root->right = helper(preorder, right_inorder, root_index);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int root_index = 0;
        return helper(preorder, inorder, root_index);
    }
};