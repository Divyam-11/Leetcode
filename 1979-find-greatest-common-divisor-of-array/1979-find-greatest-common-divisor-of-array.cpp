class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int greatest = INT_MIN;
        for(int i = 0 ;i < nums.size();i++){
            smallest = min(smallest,nums[i]);
            greatest = max(greatest,nums[i]);
        }
        return __gcd(smallest,greatest);
    }
};