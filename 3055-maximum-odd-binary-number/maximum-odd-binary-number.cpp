class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count = 0;
        int zero_count = 0;
        for(char i : s){
            if(i == '1') count++;
            else zero_count++;
        }
        string result;
        result.push_back('1');
        count--;
        for(int i = 1;i<=zero_count;i++){
            result = "0" + result;
        }
        for(int i = 1;i<=count;i++){
            result =  "1" + result;
        }
        return result;
    }
};