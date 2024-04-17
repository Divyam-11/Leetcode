
class Solution {
    string finale;
private:
    void func(TreeNode* root, string& result, const vector<char>& char_map) {
        if (!root) return;
        
        result.push_back(char_map[root->val]);
        
        if (!root->left && !root->right) {
            string temp = result;
            reverse(temp.begin(), temp.end());
            if (finale.empty() || temp < finale) {
                finale = temp;
            }
        }
        
        func(root->left, result, char_map);
        func(root->right, result, char_map);
        
        result.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        vector<char> char_map(26);
        char temp = 'a';
        for (int i = 0; i < 26; i++) {
            char_map[i] = temp++;
        }
        string result;
        func(root, result, char_map);
        return finale;
    }
};