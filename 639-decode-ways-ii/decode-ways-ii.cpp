class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int index, string &s, vector<int> &dp) {
        if (index == s.size()) return 1;
        if (s[index] == '0') return 0;
        if (dp[index] != -1) return dp[index];

        long long one = solve(index + 1, s, dp);
        if (s[index] == '*') one = (one * 9) % MOD;

        long long two = 0;

        if (index + 1 < s.size()) {
            char a = s[index];
            char b = s[index + 1];

            if (a == '*' && b == '*') {
                
                two = (15LL * solve(index + 2, s, dp)) % MOD;
            }
            else if (a == '*') {
                if (b >= '0' && b <= '6')  
                    two = (2LL * solve(index + 2, s, dp)) % MOD;
                else if (b >= '7' && b <= '9')  
                    two = (1LL * solve(index + 2, s, dp)) % MOD;
            }
            else if (b == '*') {
                if (a == '1')      
                    two = (9LL * solve(index + 2, s, dp)) % MOD;
                else if (a == '2') 
                    two = (6LL * solve(index + 2, s, dp)) % MOD;
            }
            else {
                int val = (a - '0') * 10 + (b - '0');
                if (val >= 10 && val <= 26)
                    two = solve(index + 2, s, dp);
            }
        }

        return dp[index] = (one + two) % MOD;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, dp);
    }
};
