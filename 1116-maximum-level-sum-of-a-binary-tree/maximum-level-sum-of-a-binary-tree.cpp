class Solution {
public:
    int maxLevelSum(TreeNode* root) {
                if(root == NULL) return 0;
        int result = INT_MIN;
        queue<TreeNode*> levels;
        TreeNode* temp = root;
        int level = 1;
        levels.push(temp);
        levels.push(NULL);
        vector<int> row;
        int maximal_level = 1;
        while(!levels.empty()){
            
            temp = levels.front();
            levels.pop();
            if(temp == NULL){
            if(result < accumulate(row.begin(),row.end(),0)){
                result = accumulate(row.begin(),row.end(),0);
                        maximal_level = level;
                    }
                if(!levels.empty()){

                    levels.push(NULL);

                    level++;
                    
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
            if(result < accumulate(row.begin(),row.end(),0)){
                result = accumulate(row.begin(),row.end(),0);
                        maximal_level = level;
                    }
    return maximal_level;
    }
};