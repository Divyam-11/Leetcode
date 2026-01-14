class Solution {
public:
    typedef long long ll;

    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<ll> L(n + 1, 0), T(n + 1, 0);

        for (int i = 0; i < n; i++)
            L[i + 1] = L[i] + (s[i] == 'L');

        for (int i = n - 1; i >= 0; i--)
            T[i] = T[i + 1] + (s[i] == 'T');

        ll addC = 0, addL = 0, addT = 0, bestC = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                addC += L[i] * T[i + 1];
                addL += (L[i] + 1) * T[i + 1];
                addT += L[i] * (T[i + 1] + 1);
            } else {
                bestC = max(bestC, L[i] * T[i]);
            }
        }

        addC += bestC;
        return max({addL, addT, addC});
    }
};
