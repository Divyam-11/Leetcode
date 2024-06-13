class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveArray;
        vector<int> negativeArray;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]>=0) positiveArray.push_back(nums[i]);
            else negativeArray.push_back(nums[i]);
        }
        bool positive = true;
        int i = 0,j = 0;
        vector<int> result;
    while (i<positiveArray.size() || j < negativeArray.size())
    {
        if(positive){
            if(i>=nums.size() ) continue;
            result.push_back(positiveArray[i]);
            i++;
            positive = !positive;
        }
        else {
            if(j>=nums.size()) continue;
            result.push_back(negativeArray[j]);
            j++;
            positive = !positive;
        }
    }
    return result;
    }
};