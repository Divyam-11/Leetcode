class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = '{';
        for(int i = 0 ;i < letters.size();i++){
            if(letters[i] > target){
                res = min(res,letters[i]);
            }
        }
        if(res == '{')return letters[0];
        return res;
    }
};