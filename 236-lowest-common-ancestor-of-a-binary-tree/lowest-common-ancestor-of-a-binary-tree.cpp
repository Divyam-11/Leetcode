class Solution {
private:
TreeNode* LCA;
    bool searchBST(TreeNode* root, TreeNode* p) {

    if (root == nullptr) {
        return false;
    } else if (root->val == p->val) {
        return true;
        
    }
    return searchBST(root->left,p) || searchBST(root->right,p);
    }
public:
    void helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return ;
        if(searchBST(root,p) && searchBST(root,q)) {
            LCA = root;
        }
        helper(root->left,p,q);
        helper(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode*p,TreeNode* q){
        helper(root,p,q);
        return LCA;
    }
};
