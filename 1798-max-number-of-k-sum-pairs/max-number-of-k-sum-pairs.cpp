class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0 ;
        sort(nums.begin(),nums.end());
        int left = 0 ;
        int right = nums.size() - 1;
        while(left<right){
            if(nums[left] + nums[right] < k){
                left++;
            }
            else if(nums[left ] + nums[right] == k){
                left++;
                right--;
                result++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};