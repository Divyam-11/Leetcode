class Solution {
private:
    int rober1(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[0] = nums[0];
        for(int i = 1 ;i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick+=dp[i-2];
            int not_pick = dp[i-1];
            dp[i] = max(pick,not_pick);
        }
        return dp[dp.size()-1];

    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp1,temp2;
        for(int i = 0; i < nums.size(); i++) {
            if(i!= 0)
            temp1.push_back(nums[i]);
            if(i!=nums.size() -1)
            temp2.push_back(nums[i]);
        }
        return max(rober1(temp1),rober1(temp2));
    }
};