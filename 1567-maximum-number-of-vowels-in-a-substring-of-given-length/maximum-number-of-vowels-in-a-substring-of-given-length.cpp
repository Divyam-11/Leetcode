class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int l = 0;
        int r = k - 1;
        
        for(int i = 0 ; i <k;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i ] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }
        }
        int max_count = count;
        for(int i = k-1 ;i < s.size();){
        if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u'){
                count--;
            }
        l++;
        i++;
        if(s[i] == 'a' || s[i] == 'e' || s[i ] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            
        }
        
        max_count = max(max_count,count);

        }   
    return max_count;     
    }
};