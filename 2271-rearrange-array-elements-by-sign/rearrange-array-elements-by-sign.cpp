class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int positive_index = 0;
        int negative_index = 1;
        for(int i= 0 ; i<nums.size();i++){
            if(nums[i]>=0){
                ans[positive_index] = nums[i];
                positive_index +=2;
            }
            else{
                ans[negative_index] = nums[i];
                negative_index +=2;
            }

        }
    return ans;
    }
};