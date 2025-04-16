class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long answer = 0;
        int pair_count = 0;
        unordered_map<int, int> mp;
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {   
            mp[nums[i]]++;
            pair_count += mp[nums[i]] - 1;
            while (l <= i && pair_count >= k)
            {   cout<<nums.size() - i << endl;
                answer += nums.size() - i;
                mp[nums[l]]--;
                pair_count-= mp[nums[l]];
                l++;
            }

        }
        return answer;
    }
};