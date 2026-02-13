class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long count = 0;
        set<pair<long long, int>> st; // {val,idx}
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert({nums[i], i});
            long long mi = (*st.begin()).first;
            long long mx = (*st.rbegin()).first;
            while ((mx - mi) * (i - l + 1) > k)
            {
                
                st.erase({nums[l], l});
                l++;
                mi = (*st.begin()).first;
                mx = (*st.rbegin()).first;
            }
            count += (i - l + 1);
        }
        return count;
    }
};