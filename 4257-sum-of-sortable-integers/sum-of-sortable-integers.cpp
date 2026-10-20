class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int k) -> bool {
            int prevMax = INT_MIN;

            for (int i = 0; i < n; i += k) {
                int mn = INT_MAX, mx = INT_MIN;
                int drops = 0;

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (j > i && nums[j - 1] > nums[j])
                        drops++;
                }

                if (nums[i + k - 1] > nums[i])
                    drops++;

                if (drops > 1 || prevMax > mn)
                    return false;

                prevMax = mx;
            }

            return true;
        };

        int ans = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k == 0) {
                if (check(k))
                    ans += k;

                int other = n / k;

                if (other != k && check(other))
                    ans += other;
            }
        }

        return ans;
    }
};