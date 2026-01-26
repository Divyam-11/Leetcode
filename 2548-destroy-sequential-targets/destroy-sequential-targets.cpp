class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        sort(nums.begin(), nums.end());
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
        int res = 0;
        for(int i = 0 ;i < nums.size();i++){

            if(mp[nums[i] % space ]== maxfreq){
                return nums[i];
            }
        }
        return maxEle;
    }
};
