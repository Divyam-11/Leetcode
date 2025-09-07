class Solution
{
public:
    int minOperations(string s)
    {
        int ops = 0;
        sort(s.begin(), s.end());
        string cleaned = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                continue;
            if (!cleaned.empty() && cleaned.back() == s[i])
                continue;
            cleaned.push_back(s[i]);
        }
        if (cleaned.size() <= 1)
        {
            if(cleaned.empty()) return 0;
            return 'z' - cleaned[0] + 1;
        }
        for (int i = 1; i < cleaned.size(); i++)
        {
            ops += (cleaned[i] - cleaned[i - 1]);
        }
        ops += ('z' - cleaned.back() + 1);
        return ops;
    }
};