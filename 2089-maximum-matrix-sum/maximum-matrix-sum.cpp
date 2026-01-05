class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long maxSum = 0;
        int mini = INT_MAX;
        int negs = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                maxSum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    negs++;
                mini = min(mini, abs(matrix[i][j]));
            }
        }
        if (negs % 2 == 0)
            return maxSum;
        else
            return maxSum - 2*mini;
    }
};