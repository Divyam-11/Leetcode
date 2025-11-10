class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ops = 0;
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            
            while (!st.empty() && st.top() > nums[i])
            {
                st.pop();
                ops++;
            }
            if (!st.empty() && st.top() == nums[i])
                continue;
            st.push(nums[i]);
        }
        while (!st.empty())
        {   
            int temp = st.top(  );
            st.pop();
            if(temp != 0)
            ops++;
        }
        return ops;
    }
};