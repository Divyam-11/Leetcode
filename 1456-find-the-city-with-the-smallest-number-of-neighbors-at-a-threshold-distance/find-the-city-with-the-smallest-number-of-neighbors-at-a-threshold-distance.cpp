class Solution
{
    vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
        vector<int> distance(adj.size(), INT_MAX);

        distance[src] = 0;
        st.push({0, src});
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();
            int dis = temp.first;
            int node = temp.second;
            for (pair<int, int> &i : adj[node])
            {

                int temp_distance = (dis + i.second);
                if (distance[i.first] > temp_distance)
                {
                    distance[i.first] = temp_distance;
                    st.push({temp_distance, i.first});
                }
            }
        }
        return distance;
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int result = 0;
        int city_number = INT_MAX;
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> answer = dijkstra(adjList, i);
            int count = 0;
            for (int j = 0; j < answer.size(); j++)
            {
                if (j == i)
                    continue;
                if (answer[j] <= distanceThreshold)
                    count++;
            }
            if (count <= city_number)
            {
                result = i;
                city_number = count;
            }
        }
        return result;
    }
};