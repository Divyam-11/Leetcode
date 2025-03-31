class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int piv) {
        vector<int>less;
        vector<int>more;
        vector<int>ans;
        vector<int>mid;
        for(auto a: nums){
            if(a<piv){
                less.push_back(a);
            }
            else if(a==piv){
                mid.push_back(a);
            }
            else{
                more.push_back(a);
            }
        }
        for(auto a: less){
            ans.push_back(a);
        }
         for(auto a: mid){
            ans.push_back(a);
        }
         for(auto a: more){
            ans.push_back(a);
        }
        
        return ans;
    }
};