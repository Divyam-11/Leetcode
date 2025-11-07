class Solution
{
public:
    string longestCommonPrefix(vector<string> &str)
    {
        int ptr = 0;
        string pre;
        while (1){
            for (int i = 0; i < str.size(); i++)
            {
                if (ptr >= str[i].size())
                    return pre;
                if (str[0][ptr] != str[i][ptr])
                {
                    return pre;
                }

            }
                            pre.push_back(str[0][ptr]);
                ptr++;
        }
        return pre;
    }
};