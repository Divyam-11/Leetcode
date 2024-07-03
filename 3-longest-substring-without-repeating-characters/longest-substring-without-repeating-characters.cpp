    class Solution
    {
    public:
        int lengthOfLongestSubstring(string s)
        {   int l = 0;
            int result = 0;
            unordered_map<char,int> m;
            for(int i = 0 ;i < s.size();i++){
            while(m[s[i]] != 0 ){
                m[s[l]]--;
                l++;
                
            }



            m[s[i]]++;
            result = max(result,i-l+1);
            }




            return result;
        }
    };