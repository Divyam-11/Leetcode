class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int res = 1;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        if(mp[1]%2 == 1) res = max(res,mp[1]);
        res = max(res,mp[1]-1);
        for (auto i : nums)
        {
            
            int val = i;
            // cout<<val<<endl;
            int temp_res = 1;
            if(val == 1) continue;
            while (val > 1)
            {
                int root = (int)sqrt(val);
                int checker = root * root;
                // cout<<checker<<" "<<val<<" "<<mp[sqrt(val)]<<endl;; 
                if (checker == val && mp[root] >= 2)
                {
                  
                    temp_res+=2;
                    // cout<<val<<endl;
                    // cout<<temp_res<<endl;
                    res = max(temp_res, res);
                }
                else
                    break;
                val = root;
            }
        }
        return res;
    }
};