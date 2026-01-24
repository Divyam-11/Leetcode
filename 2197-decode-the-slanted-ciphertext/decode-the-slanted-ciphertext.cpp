class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {   if(encodedText.empty()) return "";
        int col = encodedText.size() / rows;
        string res;
        for (int i = 0; i < col; i++)
        {
            int x = 0;
            int j = i;
            while (x < rows && j < col)
            {

                res.push_back(encodedText[x * col + j]);
                x++;
                j++;
            }
        }
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }
};