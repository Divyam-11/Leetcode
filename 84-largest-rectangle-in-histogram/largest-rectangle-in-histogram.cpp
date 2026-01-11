class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<pair<int, int>> st; // {height,index}
        for (int i = 0; i < heights.size(); i++)
        {
            if (st.empty())
            {
                st.push({heights[i], i});
                continue;
            }
            int last_pop_idx = i;
            while (!st.empty() && st.top().first > heights[i])
            {
                last_pop_idx = st.top().second;
                maxArea = max((st.top().first * (((i - 1) - st.top().second) + 1)), maxArea);
                st.pop();
            }
            st.push({heights[i], last_pop_idx});
        }
        int i = heights.size();
        while (!st.empty())
        {
            maxArea = max((st.top().first * (((i - 1) - st.top().second) + 1)), maxArea);
            st.pop();
        }
        return maxArea;
    }
};