class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      for(int i = 0; i<nums.size();i++){
        if(nums[abs(nums[i])-1]<0){
          return abs(nums[i]);
        }
        else {
          nums[abs(nums[i])-1] *= -1;

        }
        // nums[i] -> i-1; (-ve sign)
        // check abs of each number
        // then check i-1 is -ve if yes push to answer array
              }
        return 0;
    }
};