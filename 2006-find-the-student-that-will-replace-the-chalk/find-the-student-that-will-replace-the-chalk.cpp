class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
       for(int i = 0 ; i < chalk.size();i++){
        sum += chalk[i];
       }
       int new_k = k % sum;
       for(int i = 0 ; i < chalk.size();i++){
        if(new_k < chalk[i])
        return i;
        new_k -=chalk[i];
       }
       return 0;
    }
};