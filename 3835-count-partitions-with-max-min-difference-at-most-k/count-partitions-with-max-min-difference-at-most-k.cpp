class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> dp(n+1,0);
        vector<int> ps(n+1,0);
        dp[0]=1;
        ps[0]=1;
        deque<int> inc;
        deque<int> dec;
        for(int l = 0, r = 0; r<nums.size();++r){
            while(!inc.empty()&&nums[inc.back()]>=nums[r]){
                inc.pop_back();
            }
            inc.push_back(r);
            while(!dec.empty()&&nums[dec.back()]<=nums[r]){
                dec.pop_back();
            }
            dec.push_back(r);
            while(nums[dec.front()]-nums[inc.front()]>k){
                if(dec.front()==l){
                    dec.pop_front();
                }
                if(inc.front()==l){
                    inc.pop_front();
                }
                l++;
            }
            dp[r+1] = ps[r];
            if(l!=0){
                dp[r+1]-=ps[l-1];
                dp[r+1]+=mod;
                dp[r+1]%=mod;
            }
            ps[r+1]=ps[r];
            ps[r+1]+=dp[r+1];
            ps[r+1]%=mod;
        }
        return dp[n];
    }
};