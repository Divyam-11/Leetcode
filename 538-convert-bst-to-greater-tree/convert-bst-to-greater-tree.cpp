/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* temp = root;
        int right_sum = 0;
        helper(temp,right_sum);
        return root;
    }
};