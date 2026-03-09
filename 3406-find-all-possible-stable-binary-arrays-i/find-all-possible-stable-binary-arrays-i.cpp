class Solution {
public:
    int mod = 1e9 + 7;
    int dp[201][201][2];

    int solve(int o, int z, bool last1, int lim) {
        if(o == 0 && z == 0) {
            return 1;
        }

        if(dp[o][z][last1] != -1) {
            return dp[o][z][last1];
        }

        int ans = 0;

        if(last1) { // place 0s
            for(int l = 1; l <= min(z, lim); l++) {
                ans = (ans + solve(o, z - l, 0, lim)) % mod;
            }
        } 
        else { // place 1s
            for(int l = 1; l <= min(o, lim); l++) {
                ans = (ans + solve(o - l, z, 1, lim)) % mod;
            }
        }

        return dp[o][z][last1] = ans;
    }

    int numberOfStableArrays(int z, int o, int lim) {
        memset(dp, -1, sizeof(dp));

        int s1 = solve(o, z, 0, lim);
        int s0 = solve(o, z, 1, lim);

        return (s1 + s0) % mod;
    }
};