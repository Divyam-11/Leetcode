class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
long long ans = 0;
int minkPos = -1;
int maxKPos = -1;
int culpritIdx= -1;
for(int i = 0 ;i <nums.size();i++){
  if(nums[i] < minK || nums[i]>maxK){
    culpritIdx = i;
  }
  if(nums[i] == minK) minkPos = i;
  if(nums[i] == maxK) maxKPos = i;
  long long smaller = min(minkPos,maxKPos);
  long long temp = smaller -culpritIdx;
  ans+=(temp<=0)?0:temp;
}
return ans;
}
};