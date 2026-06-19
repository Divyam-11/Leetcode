class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int final_res = 0;
        for(int i = 0 ;i < gain.size();i++){
            res+=gain[i];
            final_res = max(res,final_res);
        }
        return final_res;
    }
};