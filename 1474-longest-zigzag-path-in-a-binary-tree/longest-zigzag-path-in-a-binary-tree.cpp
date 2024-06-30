class Solution {
int maxPath = 0;
void  dfs(TreeNode* root,int steps,bool goleft){

if(root == NULL) return;
maxPath = max(maxPath,steps);
if(goleft == true){
    dfs(root->left,steps+1,false);
    dfs(root->right,1,true);
}
else {
    dfs(root->right,steps+1,true);
    dfs(root->left,1,false);
}

}
public:
    int longestZigZag(TreeNode* root) {
        dfs(root,0,false);
        dfs(root,0,true);
        return maxPath;
}};