class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            map<int, int> m, cnt;
            for (int j = i; j < n; j++) {
                if (m.find(nums[j]) != m.end()) {
                    cnt[m[nums[j]]]--;
                    if (!cnt[m[nums[j]]]) cnt.erase(m[nums[j]]);
                }
                m[nums[j]]++;
                cnt[m[nums[j]]]++;
                if (m.size() == 1) ans = max(ans, j - i + 1);
                else if (cnt.size() == 2) {
                    int v1 = -1, v2 = -1;
                    for (auto &c : cnt) {
                        if (v1 == -1) v1 = c.first;
                        v2 = c.first;
                    }
                    if (v2 == 2 * v1) ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};