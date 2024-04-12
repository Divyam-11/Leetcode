class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        vector<int> lm(n),rm(n);
        int i,max=-1; 
        for(i=0;i<n;i++){
            if(max < height[i]){
                max = height[i];
            }
            lm[i]=max;
        }
        max=-1; 
        for(i=n-1;i>=0;i--){
            if(max < height[i]){
                max = height[i];
            }
            rm[i]=max;
        }
        int ans =0;
        for(i=0;i<n;i++){
            int val=min(lm[i],rm[i]);
            ans += val-height[i];
        }
        return ans;
    }
};