class Solution {
private: 
bool searchBST(TreeNode* root, TreeNode* target) {
    if (root == nullptr) {
        return false;
    }

    if (root == target || searchBST(root->left, target) || searchBST(root->right, target)) {
        return true;
    }

    return false;
}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> levels;
        TreeNode* temp;
        TreeNode* LCA;
        levels.push(root);
        while(!levels.empty()){
            temp = levels.front();
            levels.pop();
            if(searchBST(temp,p) && searchBST(temp,q)){
                LCA = temp;
            }
            if(temp->left) levels.push(temp->left);
            if(temp->right) levels.push(temp->right);

        }
        return LCA;
    }
};