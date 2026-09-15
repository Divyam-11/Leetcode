class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            int end = min(helper(s, k, i, i, start), helper(s, k, i, i + 1, start));
            if(end != INT_MAX){
                start = end + 1;
                ans++;
            }
        }
        return ans;
    }
    int helper(string& s, int k, int i, int j, int start){
        int n = s.size();
        for(; start <= i && j < n && s[i] == s[j]; i--, j++){
            if(j - i + 1 == k || j - i + 1 == k + 1){
                return j;
            }
        }
        return INT_MAX;
    }
};