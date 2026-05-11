class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int i = 0 ;i < nums.size();i++){
            string temp = to_string(nums[i]);
            for(auto x : temp){
                res.push_back(x-'0');
            }
        }
        return res;
    }
};