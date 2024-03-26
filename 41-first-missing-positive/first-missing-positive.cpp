class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      unordered_map<int,int> m;
      int maximum_number = INT_MIN;
      for(int i = 0 ; i<nums.size();i++) {
        m[nums[i]]++;
        maximum_number = max(maximum_number,nums[i]);
      }
      for(int i = 0;i<maximum_number;i++){
        if(m[i] == 0 && i>0 ) return i;
      }
      if(maximum_number < 1) return 1;
            return maximum_number+1;

    }
};