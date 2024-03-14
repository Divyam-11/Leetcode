class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        int result = 0;
        int currsum = 0;
        m[0] = 1;
        for(int&i: nums){
            currsum+=i;
            int left = currsum - goal;
            if(m.find(left) != m.end()){
                result+=m[left];
            }
            m[currsum]++;
        }
        return result;
    }
};