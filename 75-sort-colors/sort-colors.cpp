class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> result;
        for(int i : nums){
            result[i]++;
        }
        nums.clear();
        for(int i = 0;i<result[0];i++){
            nums.push_back(0);
        }
        for(int i = 0;i<result[1];i++){
            nums.push_back(1);
        }
        for(int i = 0;i<result[2];i++){
            nums.push_back(2);
        }
    }
};