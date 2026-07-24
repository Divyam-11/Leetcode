class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0 ;i < nums.size();i++){
            for(int j = i ;j < nums.size();j++){
                
                    st.insert(nums[i] ^ nums[j]);
                
            }
        }
        unordered_set<int> st2;
        for(auto i : st){
            for(int j = 0 ;j <nums.size();j++){
                st2.insert(nums[j] ^ i);
            }
        }
        return st2.size();
    }
};