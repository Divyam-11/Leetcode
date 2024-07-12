
class Solution {
private:
TreeNode* build(vector<int> &preorder,vector<int> &inorder,int & root,int left, int right){
    if(left > right )return NULL;
    int pivot = left;
    while(inorder[pivot] != preorder[root]) pivot++;


    root++;
    TreeNode* newNode = new TreeNode(inorder[pivot]);
    newNode->left = build(preorder,inorder,root,left,pivot-1);
    newNode->right = build(preorder,inorder,root,pivot+1,right);
    return newNode;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }

};