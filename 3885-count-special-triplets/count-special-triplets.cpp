class Solution {
public:
    const int MOD = 1e9 + 7;
    long long nC2_safe(long long n) {
        if (n < 2)
            return 0;
        return (n / 2) * (n - 1);
    }

    int specialTriplets(vector<int>& nums) {
        long long res = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]--;
            int c = nums[i] * 2;
            if (mp.find(c) != mp.end()) {
                if (freq.find(c) != freq.end()) {
                    long long temp = 1LL * mp[c] * freq[c];
                    temp %= MOD;
                    res = (res + temp) % MOD;
                }
            }
            mp[nums[i]]++;
        }
        return res;
    }
};