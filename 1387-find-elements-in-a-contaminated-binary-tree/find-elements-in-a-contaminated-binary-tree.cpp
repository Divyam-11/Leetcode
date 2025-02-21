class FindElements {
public:
TreeNode* temp;
unordered_map<int,int> mp;
    void inorder(TreeNode* root , int value){
        if(!root) return ;
        inorder(root->left,2 * value + 1);
        root->val = value;
        mp[value]++;
        inorder(root->right,2 * value + 2);

    }
    FindElements(TreeNode* root) {
        temp = root;
        inorder(root,0);
    }

    bool find(int target) {
        if(mp[target] != 0) return true;
        return false;
    }
};