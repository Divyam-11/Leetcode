class Solution {
public:
    using ull = unsigned long long;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const ull BASE = 911382323;

        vector<ull> power(n + 1, 1);
        vector<ull> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            power[i + 1] = power[i] * BASE;
            pref[i + 1] = pref[i] * BASE + nums[i] + 1;
        }

        auto getHash = [&](int l, int r) {
            return pref[r + 1] - pref[l] * power[r - l + 1];
        };

        auto possible = [&](int len) {
            unordered_map<ull, int> freq;

            for (int i = 0; i + len - 1 < n; i++) {
                ull h = getHash(i, i + len - 1);
                freq[h]++;
            }

            for (auto &p : freq) {
                if (p.second == 1) return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};