class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> dp(n, 0);

        dp[0] = 1;

        int count = 0;

        for (int idx = 1; idx < n; idx++) {

            if (idx - minJump >= 0) {
                count += dp[idx - minJump];
            }

            if (idx - maxJump - 1 >= 0) {
                count -= dp[idx - maxJump - 1];
            }

            if (count > 0 && s[idx] == '0') {
                dp[idx] = 1;
            }
        }

        return dp[n - 1];
    }
};