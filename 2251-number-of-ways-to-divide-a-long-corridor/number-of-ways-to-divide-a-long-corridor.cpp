class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfWays(string s) {
        vector<pair<int,int>> v;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'S'){
                auto j = i+1;
                while(j < n and s[j] != 'S'){
                    j++;
                }
                if(j < n and s[j] == 'S'){
                    v.emplace_back(i,j);
                }
                if(j == n){
                    return 0;
                }
                i += (j-i);
            }
        }
        if(v.size() <= 1) return v.size();
        long long ans = 1;
        for(int i = 1 ; i < v.size() ; i++){
            ans = (ans%MOD * (v[i].first - v[i-1].second)%MOD)%MOD;
        }
        return ans;
    }
};