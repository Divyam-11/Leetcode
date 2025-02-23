class Solution
{
public:
    TreeNode *build(int index, vector<int> &preorder, vector<int> &postorder)
    {
        if (index >= preorder.size())
            return nullptr;
        if (postorder.empty())
            return nullptr;
            
        TreeNode *root = new TreeNode(preorder[index]);
        // If there is only one element, it's a leaf node.
        if(preorder.size() == 1) return root;
        
        index++;  // Move to the next element which will be the left child.
        int i = 0;
        // Find the index of the left child's value in postorder.
        for(; i < postorder.size(); i++){
            if(postorder[i] == preorder[index])
                break;
        }
        // Now, i is the index of the left child's value in postorder.
        // The left subtree size is (i + 1).
        vector<int> leftPreorder(preorder.begin() + index, preorder.begin() + index + i + 1);
        vector<int> rightPreorder(preorder.begin() + index + i + 1, preorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + i + 1);
        // Exclude the last element of postorder since it's the current root.
        vector<int> rightPostorder(postorder.begin() + i + 1, postorder.end() - 1);
        
        root->left = build(0, leftPreorder, leftPostorder);
        root->right = build(0, rightPreorder, rightPostorder);
        return root;
    }
    
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return build(0, preorder, postorder);
    }
};
