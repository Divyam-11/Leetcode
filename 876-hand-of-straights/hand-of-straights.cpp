class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize)
            return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < hand.size(); i++)
        {
            mp[hand[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mp)
        {
            pq.push({it.first, it.second});
        }
        while (!pq.empty())
        {
            vector<pair<int, int>> temp;
            for (int i = 0; i < groupSize; i++)
            {
                if (!pq.empty() && temp.empty())
                {
                    auto temp1 = pq.top();
                    temp1.second--;
                    temp.push_back(temp1);
                    pq.pop();
                }
                else if (!pq.empty() && temp.back().first + 1 == pq.top().first)
                {
                    auto temp1 = pq.top();
                    temp1.second--;
                    temp.push_back(temp1);
                    pq.pop();
                }
                else
                    return false;
            }
            while (!temp.empty())
            {
                if (temp.back().second)
                    pq.push(temp.back());
                temp.pop_back();
            }
        }

        return true;
    }
};