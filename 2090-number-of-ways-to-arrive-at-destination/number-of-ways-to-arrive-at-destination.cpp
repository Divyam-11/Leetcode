class Solution
{
public:
    int mod = (int)(1e9 + 7);
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < roads.size(); i++)
        {
            adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        distance[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        // {distance , node}
        pq.push({0, 0});
        while (!pq.empty())
        {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            for (int i = 0; i < adjList[node].size(); i++)
            {
                long long edW = adjList[node][i].second;
                int adjNode = adjList[node][i].first;
                if ((edW + dis) < distance[adjNode])
                {
                    pq.push({edW + dis, adjNode});
                    distance[adjNode] = edW + dis;
                    ways[adjNode] = ways[node];
                }
                else if (edW + dis == distance[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};