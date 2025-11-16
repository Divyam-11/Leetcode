class Solution
{
public:
    int minLengthAfterRemovals(string s)
    {
        stack<int> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return abs(count);
    }
};