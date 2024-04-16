class Solution {
private:
void inorder(TreeNode* root,int val,int level,int depth){
if(!root) return;
if(level == depth-1){
    TreeNode* temp = root->left;
    root->left = new TreeNode(val);
    root->left->left = temp;
    temp = root->right;
    root->right = new TreeNode(val);
    root->right->right = temp;
    return;
}
if(root->left){
    inorder(root->left,val,level+1,depth);

}
if(root->right){
    inorder(root->right,val,level+1,depth);
}

}
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth == 1){
            TreeNode* ptr = new TreeNode(val);
            ptr->left = root;
            return ptr;
        }
        inorder(root,val,1,depth);
        return root;
    }
};