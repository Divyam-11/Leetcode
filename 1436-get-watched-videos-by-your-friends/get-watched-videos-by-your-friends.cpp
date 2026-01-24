class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        queue<pair<int, int>> q; // {id,level};
        q.push({id, 0});
        unordered_map<string, int> mp; // {video,freq}
        vector<int> visited(n);
        
        while (!q.empty())
        {
            int temp_id = q.front().first;
            int lvl = q.front().second;
            visited[temp_id] = 1;
            q.pop();
            if (lvl == level)
            {
                for (auto vid : watchedVideos[temp_id])
                {
                    mp[vid]++;
                }
            }
            if (lvl < level)
            {
                for (auto frnd : friends[temp_id])
                {
                    if (!visited[frnd])
                    {    q.push({frnd, lvl + 1});
                    visited[frnd] = 1;}
                }
            }
        }
        vector<pair<int, string>> temp;
        for (auto i : mp)
        {
            temp.push_back({i.second, i.first});
        }
        sort(temp.begin(), temp.end());
        vector<string> res;
        for (int i = 0; i < temp.size(); i++)
        {
            res.push_back(temp[i].second);
        }
        return res;
    }
};