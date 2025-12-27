class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int last_dup = -1;
        unordered_set<int> st;
        for (int i = nums.size()-1; i >=0; i--)
        {
            if (st.find(nums[i]) != st.end())
            {
                last_dup = i;
                break;
            }
            st.insert(nums[i]);
        }
        if (last_dup == -1)
            return 0;
        cout << last_dup << endl;
        return (last_dup / 3 + 1);
    }
};