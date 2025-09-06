class Solution {
public:
    int intLog4(long long n) {
        int res = 0;
        while (n >= 4) {
            n >>= 2;
            res++;
        }
        return res;
    }

    long long pow4(int k) { return 1LL << (2 * k); }
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for (int i = 0; i < queries.size(); i++) {
            long long l = queries[i][0];
            long long u = queries[i][1];
            long long ops = 0;
            while (l <= u) {
                long long val = intLog4(l);
                long long u1 = pow4(val + 1) - 1;

                u1 = min(u, u1);

                ops += (u1 - l + 1) * (val + 1);
                l = u1 + 1;
            }
            result += (ops + 1) / 2;
        }
        return result;
    }
};