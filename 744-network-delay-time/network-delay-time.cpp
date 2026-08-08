class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int w = times[i][2];
            adjList[u].push_back({v, w});
        }
        k--;
        vector<int> visited(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        visited[k] = 0;
        while (!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adjList[node])
            {
                if (it.second + weight < visited[it.first])
                {
                    visited[it.first] = it.second + weight;
                    pq.push({it.second + weight, it.first});
                }
            }
        }
        int res = *max_element(visited.begin(), visited.end());
        return res == INT_MAX ? -1 : res;
    }
};