class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> max_right_element(nums.size(),0);
        max_right_element[nums.size()-1] = nums[nums.size()-1];
        for(int i  = nums.size()-2;i>=0;i--){
            max_right_element[i] = max(max_right_element[i+1],nums[i]);
        }
    int ans = 0;
    int l = 0 ;
    int r = 1;
    while(l<=r && r < nums.size()){
        while(r< nums.size() && max_right_element[r] >= nums[l]){
            ans = max(ans,r-l);
            r++;
        }
        l++;
    }
    return ans;
}
};