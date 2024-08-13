class Solution {
private:
vector<vector<int>> ans;
void solve(int index,int target,vector<int> &nums,vector<int> &answer){
if(target == 0){
    ans.push_back(answer);
    return;
}
for(int i = index;i<nums.size();i++){
    if(nums[i]>target){
        break;
    }
    else if(i>index && nums[i] == nums[i-1]) continue;
    answer.push_back(nums[i]);
    solve(i+1,target - nums[i],nums,answer);
    answer.pop_back();
}
}
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> answer;
        sort(nums.begin(),nums.end());
        solve(0,target,nums,answer);
        return ans;
    }
};