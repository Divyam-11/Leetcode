class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {

        int n = capacity.size();
        vector<long long> prefix(n);
        prefix[0] = capacity[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (long long)capacity[i];
        }

        long long res = 0;
        map<long long, map<long long, long long>> seen;

        for (int i = 1; i < n; i++) {
            long long targetPrefix = prefix[i] - 2LL * capacity[i];
            res += seen[targetPrefix][capacity[i]];
            seen[prefix[i - 1]][capacity[i - 1]]++;
        }

        return res;
    }
};
