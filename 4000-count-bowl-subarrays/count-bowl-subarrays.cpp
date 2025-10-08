class Solution
{
public:
    long long bowlSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> L(nums.size(), -1);
        vector<int> R(nums.size(), -1);
        stack<int> st;
        // greatest right
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                L[i] = st.top();
            }
            st.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                R[i] = st.top();
            }
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (L[i] != -1 && i - L[i] >= 2)
                res++;
            if (R[i] != -1 && R[i] - i >= 2)
                res++;
        }
        return res;
    }
};