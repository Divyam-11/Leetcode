class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        vector<int> rowC(mat.size());
        vector<int> colC(mat[0].size());
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {

                rowC[i] += mat[i][j];
                colC[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1 && rowC[i] == 1 && colC[j] == 1)
                {
                    res++;
                }
            }
        }

        return res;
    }
};