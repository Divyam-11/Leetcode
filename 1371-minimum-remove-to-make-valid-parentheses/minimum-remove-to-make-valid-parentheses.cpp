class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        int count = 0 ;
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == '(') count ++;
            else if(s[i] == ')') {
                count--;
                 if(count < 0 ) {
                    count++;
                    continue;
                }
            }
            result+=s[i];
        }
     count = 0;
        string result_2 = "";
        for(int i = result.size() - 1;i>=0;i--){
            if(result[i] == ')') count++;

            else if(result[i] == '('){
                count--;
                if(count < 0 ) {
                    count++;
                    continue;
                }
            }
            result_2+=result[i];
        }
        reverse(result_2.begin(),result_2.end());
        return result_2;
    }
};