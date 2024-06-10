class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k%2 != 0 && nums.size() == 1) return -1;
        if(k == 1) return nums[1];
        int ans = -1;
        if(k > nums.size()) {
            return *max_element(nums.begin(),nums.end());
        }
        else if(k==nums.size()){
            return *max_element(nums.begin(),nums.end()-1);

        }
        else{
            for(int i = 0 ; i < k -1 ;i++){
                ans = max(nums[i],ans);

            }
            return max(ans,nums[k]);
        }

return -1;
    }
};