class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        k--;
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < times.size(); i++)
        {
            adjList[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);
        distance[k] = 0;
        pq.push({0, k}); // {distance, node} in pq and in adjlist {node,weight}'
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (int i = 0; i < adjList[node].size(); i++)
            {
                if (dis + adjList[node][i].second < distance[adjList[node][i].first])
                {
                    distance[adjList[node][i].first] = dis + adjList[node][i].second;

                    pq.push({distance[adjList[node][i].first], adjList[node][i].first});
                }
            }
        }
        int maxTime = 0;
        for (int i = 0; i < n; i++)
        {
            if (distance[i] == INT_MAX)
                return -1; // If any node is unreachable
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};