class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {   if(encodedText.empty()) return "";
        int col = encodedText.size() / rows;
        vector<string> grid(rows, string(col, ' '));
        // cout << rows << " " << col << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                grid[i][j] = encodedText[col * i + j];
                // cout << grid[i][j];
            }
            // cout << endl;
        }
        string res;
        for (int i = 0; i < col; i++)
        {
            int x = 0;
            int y = i;
            while (x < rows && y < col)
            {
                res.push_back(grid[x][y]);
                x++;
                y++;
            }
        }
        while (res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};