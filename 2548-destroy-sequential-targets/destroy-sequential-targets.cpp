class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        
        unordered_map<int, int> mp;
        int maxfreq = 0;
        int maxEle = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int ele = nums[i] % space;
            mp[nums[i] % space]++;
            int temp = mp[ele];
            if (temp > maxfreq)
            {
                maxfreq = temp;
                maxEle = ele;
            }
        }
        int res = INT_MAX;
        for(int i = 0 ;i < nums.size();i++){

            if(mp[nums[i] % space ]== maxfreq){
                res = min(nums[i],res);
            }
        }
        return res;
    }
};
