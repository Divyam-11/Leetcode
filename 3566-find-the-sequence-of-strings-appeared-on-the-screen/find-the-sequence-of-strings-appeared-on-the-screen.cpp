class Solution
{
public:
    vector<string> stringSequence(string target)
    {
        vector<string> res;
        res.push_back("a");
        int ptr = 0;
        while (res.back() != target)
        {
            string b = res.back();
            if (b.back() < target[ptr])
            {
                b[b.size() - 1]++;
                res.push_back(b);
            }
            else if (b.back() == target[ptr])
            {
                b.push_back('a');
                res.push_back(b);
                ptr++;
            }
                }
        return res;
    }
};
