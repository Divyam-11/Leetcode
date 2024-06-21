class Solution {
public:
    int func(vector<int>& nums, int k) {
    int l = 0;
    int result = 0;
    int odd_count = 0;
    for(int r = 0; r<nums.size();r++){
        if(nums[r]%2 != 0){
            odd_count++;
        }
        while(odd_count > k){
            
            if(nums[l] % 2 != 0) odd_count--;
            l++;
    }
    result += r-l+1;
    
    }
    return result;
    }
    int numberOfSubarrays(vector<int> &nums,int k){
        return func(nums,k) - func(nums,k-1);
    }
};