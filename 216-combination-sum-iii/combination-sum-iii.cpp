class Solution {
private:
    void solve(vector<vector<int>>& result, vector<int>& nums, int k, int n,int index) {
        
        if (nums.size() == k) {
            if (accumulate(nums.begin(), nums.end(), 0) == n) {
                result.push_back(nums);
            }
            return;
        }
        if(index > 9) return;
            // pick recurse backtract not pick
            nums.push_back(index);
            solve(result, nums, k, n, index + 1);
            nums.pop_back();
            solve(result, nums, k, n, index + 1);
        
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> nums;
        solve(result, nums, k, n, 1);
        return result;
    }
};