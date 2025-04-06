class Solution {
private:
    vector<vector<vector<int>>> cache;

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        cache = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1));
        return dfs(0, -1, nums);
    }

    vector<int> dfs(int i, int prevIndex, vector<int>& nums) {
        if (i == nums.size()) return {};
        if (!cache[i][prevIndex + 1].empty()) return cache[i][prevIndex + 1];

        vector<int> res = dfs(i + 1, prevIndex, nums);

        if (prevIndex == -1 || nums[i] % nums[prevIndex] == 0) {
            vector<int> tmp = {nums[i]};
            vector<int> next = dfs(i + 1, i, nums);
            tmp.insert(tmp.end(), next.begin(), next.end());
            if (tmp.size() > res.size()) res = tmp;
        }

        return cache[i][prevIndex + 1] = res;
    }
};