class Solution
{
public:
    string lexSmallest(string s)
    {
        string res = s;
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            temp = s;
            reverse(temp.begin(), temp.begin() + i);
            res = min(res, temp);
            temp = s;
            reverse(temp.begin() + i, temp.end());
            res = min(res, temp);
        }
        return res;
    }
};