class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int max_till_now = nums[0] - k;
        set<int> st;
        st.insert(max_till_now);
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = max(max_till_now + 1, nums[i] - k);
            if (temp > nums[i] + k)
            {
                st.insert(nums[i]);
                continue;
            }
            max_till_now = temp;
            st.insert(max_till_now);
        }
        return st.size();
    }
};