class Solution {
public:
    static const long long MOD = 1000000007LL;

    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
        int n = base.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1)
            return m;

        int S = 2 * m;

        vector<vector<long long>> T(S, vector<long long>(S, 0));

        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                T[v][m + u] = 1;
            }
        }

        for (int v = 0; v < m; v++) {
            for (int u = v + 1; u < m; u++) {
                T[m + v][u] = 1;
            }
        }

        vector<long long> state(S, 0);

        for (int v = 0; v < m; v++) {
            state[v] = v;
            state[m + v] = m - 1 - v;
        }

        vector<vector<long long>> P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] = (finalState[i] + P[i][j] * state[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : finalState)
            ans = (ans + x) % MOD;

        return ans;
    }
};