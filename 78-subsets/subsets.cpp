class Solution {
private:
vector<vector<int>> ans;
void solve(vector<int> &subset,vector<int> &nums,int i){
    if(i == nums.size()){
        ans.push_back(subset);
        return;
    }
    solve(subset,nums,i+1);
    subset.push_back(nums[i]);
    solve(subset,nums,i+1);
    subset.pop_back();
    
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        solve(subset,nums,0);
        return ans;
    }
};