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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
                if(root == NULL) return {};
        vector<vector<int>> result;
        queue<TreeNode*> levels;
        TreeNode* temp = root;
        levels.push(temp);
        levels.push(NULL);
        vector<int> row;
        while(!levels.empty()){
            
            temp = levels.front();
            levels.pop();
            if(temp == NULL){
                if(!levels.empty()){
                    levels.push(NULL);
                    result.push_back(row);
                    row.clear();
                }
            }
            else{
                row.push_back(temp->val);

                if(temp->left){
                    levels.push(temp->left);
                
                }
                if(temp->right) levels.push(temp->right);
            }
        }
        result.push_back(row);
        reverse(result.begin(),result.end());
    return result;
    }
};