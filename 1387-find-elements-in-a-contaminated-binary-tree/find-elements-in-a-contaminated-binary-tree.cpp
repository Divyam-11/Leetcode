class FindElements {
public:
    unordered_set<int> values;
    
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    void recover(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        values.insert(val);
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
};
