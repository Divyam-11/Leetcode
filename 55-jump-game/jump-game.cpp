class Solution {
private:
 bool func(vector<int>& nums,int index,vector<int> &dp){
    if(index >= nums.size()) return false;
    if(index == nums.size() - 1) return true;
    if(nums[index] == 0 ) return false;
    if(dp[index] != -1) return dp[index];
    bool check = false;
    for(int i = 1 ; i<=nums[index];i++){
    if(index+i<nums.size() && func(nums,index+i,dp)) return dp[index] = true;
    
    }

    return dp[index] = check;
 }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return func(nums,0,dp);
    }
};