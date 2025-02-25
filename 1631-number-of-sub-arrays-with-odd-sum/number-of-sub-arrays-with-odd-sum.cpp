class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cur_sum = 0;
        int result = 0;
        int odd = 0;
        int even = 0;
        int mod = 1e9 + 7;
        for(auto i : arr){
            cur_sum+=i;
            if(cur_sum%2){
                
                result = ( result + 1 + even)%mod;
                result%mod;
                odd++;
            }
            else{
                result = (result + odd )%mod;
                
                even++;
            }
        }
    return result;
    }
};