class Solution {
private:
void helper(TreeNode* root,int & right_sum){
    if(!root) return;
if(right_sum == 0 && !root->left && !root->right){
    right_sum = root->val;
    return ; 
}
helper(root->right,right_sum);
root->val += right_sum;
right_sum = root->val;
helper(root->left,right_sum);
return ;

}
public:
    TreeNode* bstToGst(TreeNode* root) {
        int right_sum = 0;
        helper(root,right_sum);
        return root;
    }
};