class Solution {
public:
    string removeStars(string s) {
        string result;
        for(int i = 0; i < s.size();i++){
            if(s[i] == '*'){
                result.pop_back();
                continue;
            }
            

            result.push_back(s[i]);
        }
        return result;
    }
};