class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>>levels;
        levels.push({root,{0,0}});
        while(!levels.empty()){
            auto p = levels.front();
            levels.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            m[x][y].insert(node->val);
            if(node->left) levels.push({node->left,{x-1,y+1}});
            if(node->right) levels.push({node->right,{x+1,y+1}});


        }
        vector<vector<int>> answer;
        for(auto &p:m){
            vector<int> col;
            for(auto &q : p.second){
                
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            answer.push_back(col);
        }
        return answer;
    }
};