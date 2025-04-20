class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        vector<pair<int, int>> mera_map;
        for (int i = 0; i < answers.size(); i++)
        {
            if (mera_map.empty())
            {
                mera_map.push_back({answers[i] + 1, 1});
            }
            // check if description fits
            else
            {
                bool check = false;
                for (int j = 0; j < mera_map.size(); j++)
                {
                    if (mera_map[j].first == answers[i] + 1 && mera_map[j].second < answers[i] + 1)
                    {
                        mera_map[j].second++;
                        check = true;
                        break;
                    }
                }
                if (!check)
                {
                    mera_map.push_back({answers[i] + 1, 1});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < mera_map.size(); i++)
        {
            count += mera_map[i].first;
        }
        return count;
    }
};