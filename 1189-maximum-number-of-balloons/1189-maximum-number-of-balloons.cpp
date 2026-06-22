class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26);
        string test = "balloon";
        for(int i = 0 ;i < text.size();i++){
            freq[text[i]-'a']++;
        }
        int res = INT_MAX;
        for(int i = 0 ;i < test.size();i++){
            if(test[i] == 'l' || test[i] =='o') {
                res = min(res,freq[test[i]-'a']/2);
            }
            else
            res = min(res,freq[test[i]-'a']);
        }
        return res;
    }
};