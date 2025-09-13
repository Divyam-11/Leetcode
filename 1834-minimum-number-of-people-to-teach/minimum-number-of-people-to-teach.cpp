class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        unordered_set<int> sadUsers;
        for (int i = 0; i < friendships.size(); i++)
        {
            int u = friendships[i][0];
            int v = friendships[i][1];
            bool sad = true;
            for (int i = 0; i < languages[u - 1].size(); i++)
            {
                for (int j = 0; j < languages[v - 1].size(); j++)
                {
                    if (languages[u - 1][i] == languages[v - 1][j])
                    {
                        sad = false;
                        break;
                    }
                }
            }
            if (sad)
            {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }
        int mostKnownLanugage = 0;
        vector<int> languageMap(n);
        for (auto user : sadUsers)
        {
            for (auto i : languages[user - 1])
            {
                languageMap[i - 1]++;
                mostKnownLanugage = max(mostKnownLanugage, languageMap[i - 1]);
            }
        }
        return sadUsers.size() - mostKnownLanugage;
    }
};