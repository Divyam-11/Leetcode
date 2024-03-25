class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> m;
        for(int i : nums){
            if(m.find(i) != m.end()){
                result.push_back(i);
            }
            m[i]++;
        }
        return result;
    }
};