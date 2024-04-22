class Solution {
private:
int solve(vector<int> &nums,int target,int index)
{
if(index == -1 ){
if(target == 0) return 1;
else return 0;

}

int one = solve(nums,target - nums[index],index-1);
int two = solve(nums,target + nums[index],index-1);



return one + two;




}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      return solve(nums,target,nums.size()-1);  
    }
};