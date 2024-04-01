class Solution {
public:
 int lengthOfLastWord(string s) {
    int count = 0;
    int index  = 0;
    int last = 0;
    
         
        for(auto k = s.length() - 1;k>=0;k--){
            last = k;
            if(s[k] != ' '){

            break;
            }
        }
        
        for (int x = last; x >= 0 && s[x] != ' '; x--) {
            count++;
        }
    
    return count;
        }
};