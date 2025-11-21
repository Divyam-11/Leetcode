class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && (st.size() + nums.size() - i > k) && st.back() > nums[i])
            {
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        while(st.size() > k){
            st.pop_back();
        }
        return st;
    }
};