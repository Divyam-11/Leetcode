class Solution {
public:
    int maxDepth(string s) {
        int maxD = 0;
        int depth = 0;
    for(int i = 0 ;i < s.size();i++){
        if(s[i] == '(') depth++;
        if(s[i] == ')') depth--;
         maxD = max(maxD,depth);
    }        
    return maxD;
    }
};