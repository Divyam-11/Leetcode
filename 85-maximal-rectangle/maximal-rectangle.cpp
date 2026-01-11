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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxArea = 0;
        vector<vector<int>> theMatrix(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                theMatrix[i][j] = matrix[i][j] - '0';
            }
        }
        maxArea = max(maxArea, largestRectangleArea(theMatrix[0]));
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (theMatrix[i][j] == 1)
                {
                    theMatrix[i][j] += theMatrix[i - 1][j];
                }
            }
            maxArea = max(maxArea, largestRectangleArea(theMatrix[i]));
        }
        return maxArea;
    }
};