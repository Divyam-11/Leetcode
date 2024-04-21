class Solution{
private:
vector<vector<int>> result;
void solve(int index,int target,vector<int> &nums,vector<int> &answer){
    if(index == nums.size()){
    if(target == 0){
        result.push_back(answer);
    }
    return ;
    }
    if(nums[index] <=target){
        answer.push_back(nums[index]);
solve(index,target-nums[index],nums,answer);
    answer.pop_back();
    }
    solve(index+1,target,nums,answer);
}
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> answer;
        solve(0,target,nums,answer);
        return result;
    }
};