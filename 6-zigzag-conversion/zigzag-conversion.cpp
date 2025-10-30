class Solution
{
public:
    string convert(string s, int numRows)
    {   
        if(numRows == 1) return s;
        vector<string> matrix(numRows, string(s.size(), '*'));
        int ptr = 0;
        int i = 0;
        int j = 0;
        bool zig_up = false;

        while (ptr < s.size())
        {
            matrix[i][j] = s[ptr];
            ptr++;
            if (zig_up)
            {
                i--;
                j++;
            }
            else
            {
                i++;
            }
            if (i == 0)
            {
                zig_up = false;
            }
            if (i == numRows - 1)
                zig_up = true;
        }
        string result;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] != '*')
                    result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};