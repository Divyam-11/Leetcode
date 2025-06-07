class Solution
{
public:
    string clearStars(string s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
                pq.push({-1*s[i], i});
            else
            {
                auto temp = pq.top();
                pq.pop();
                s[temp.second] = '-';
            }
        }
        string result;
        for (auto i : s)
        {
            if (i == '-' || i == '*')
            {
                continue;
            }
            result.push_back(i);
        }
        return result;
    }
};