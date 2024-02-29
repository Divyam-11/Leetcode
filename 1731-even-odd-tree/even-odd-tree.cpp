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
       bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) return true;
        bool even = true;
        
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
for (int i = 1; i < row.size(); ++i) {
    if (even) {
        if (row[i] % 2 != 1 || row[i] <= row[i - 1]) {
            return false;
        }
    } else {
        if (row[i] % 2 != 0 || row[i] >= row[i - 1]) {
            return false;
        }
    }
}
if (even) {
    for (int i = 0; i < row.size(); ++i) {
        if (row[i] % 2 != 1) {
            return false;
        }
    }
} else {
    for (int i = 0; i < row.size(); ++i) {
        if (row[i] % 2 != 0) {
            return false;
        }
    }
}
                    even = !even;
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
for (int i = 1; i < row.size(); ++i) {
    if (even) {
        if (row[i] % 2 != 1 || row[i] <= row[i - 1]) {
            return false;
        }
    } else {
        if (row[i] % 2 != 0 || row[i] >= row[i - 1]) {
            return false;
        }
    }
}

// ...

// Outside the loop where you check the order of values
if (even) {
    for (int i = 0; i < row.size(); ++i) {
        if (row[i] % 2 != 1) {
            return false;
        }
    }
} else {
    for (int i = 0; i < row.size(); ++i) {
        if (row[i] % 2 != 0) {
            return false;
        }
    }
}
    return true;
    }
};