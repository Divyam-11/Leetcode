class Solution
{
    void func(string &ans, string &tiles, vector<int> &used, unordered_set<string> &tracker)
    {
        if (ans.size() == tiles.size())
        {
            return;
        }
        for (int i = 0; i < used.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                ans.push_back(tiles[i]);
                tracker.insert(ans);
                func(ans, tiles, used, tracker);
                ans.pop_back();
                used[i] = false;
            }
        }
    }

public:
    int numTilePossibilities(string tiles)
    {
        string ans = "";
        vector<int> used(tiles.size(), false);
        unordered_set<string> tracker;
        func(ans, tiles, used, tracker);
        return tracker.size();
    }
};