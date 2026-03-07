class Solution
{
public:
    int minFlips(string s)
    {
        int odd0 = 0, odd1 = 0, even0 = 0, even1 = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (i % 2 == 0) even1++;
                else odd1++;
            }
            else
            {
                if (i % 2 == 0) even0++;
                else odd0++;
            }
        }

        if (s.size() % 2 == 0)
            return min(odd0 + even1, odd1 + even0);

        int res = min(odd0 + even1, odd1 + even0);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                even0--;
                swap(odd0, even0);
                swap(odd1, even1);
                even0++;
            }
            else
            {
                even1--;
                swap(odd0, even0);
                swap(odd1, even1);
                even1++;
            }

            int can = min(odd0 + even1, odd1 + even0);
            res = min(res, can);
        }

        return res;
    }
};