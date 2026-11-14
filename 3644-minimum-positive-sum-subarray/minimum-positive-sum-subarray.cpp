class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int result = INT_MAX ; 
        bool flag = false ;
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j < n ; j++){
                int window = j - i + 1;
                if(window >= l && window <= r){
                    int ans = 0 ;
                    for(int k = i ; k <= j ; k++){
                        ans += nums[k];
                    }
                    if(ans > 0 ){
                      result = min(result ,ans);
                      flag = true ;
                    }
                }
            }
        }
      
       return (flag == false)? -1 : result ;
   }
};