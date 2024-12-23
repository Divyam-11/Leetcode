class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < flights.size(); i++)
        {
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // {cost,{node,stops}}
        queue<pair<int,pair<int,int>>>
            pq;
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        pq.push({0, {src, 0}});
        while (!pq.empty())
        {
            int cost = pq.front().first;
            int node = pq.front().second.first;
            int stops = pq.front().second.second;
            pq.pop();
            if (stops > k)
                continue;
            for (int i = 0; i < adjList[node].size(); i++)
            {
                int temp_stops = stops + 1;
                int temp_cost = adjList[node][i].second + cost;

                if (temp_cost < distance[adjList[node][i].first] && stops <= k)
                {
                    {
                        pq.push({temp_cost, {adjList[node][i].first, temp_stops}});
                        distance[adjList[node][i].first] = temp_cost;
                    }
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};