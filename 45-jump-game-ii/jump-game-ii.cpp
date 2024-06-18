class Solution {
    int func(vector<int> &nums,int index,int jumps,vector<int> &dp){
        if(index>=nums.size()){
            return 0;
        }
        else if(index == nums.size()-1){
            return 0;
        }
        else if(dp[index] != -1) return dp[index];
        int result = 10e5;
        for(int i = 1 ; i<=nums[index];i++){
        
        result = min(result,1 + func(nums,index+i,jumps,dp));
        }
        return dp[index] = result;
    }
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        vector<int> dp(nums.size(),-1);
        return func(nums,0,jumps,dp);
    }
};