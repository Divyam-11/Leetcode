class Solution
{
public:

    int minCost(int n, vector<vector<int>> &edges)
    {

        vector<vector<pair<int, int>>> adj(n);
        int src = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        set<pair<int, int>>
            st;
        vector<int> distance(adj.size());
        for (int i = 0; i < adj.size(); i++)
        {
            distance[i] = INT_MAX;
        }
        distance[src] = 0;
        st.insert({0, src});
        while (!st.empty())
        {
            auto temp = *(st.begin());
            st.erase(temp);
            int dis = temp.first;
            int node = temp.second;
            for (pair<int, int> &i : adj[node])
            {

                int temp_distance = (dis + i.second);
                if (distance[i.first] > temp_distance)
                {
                    if (distance[i.first] != INT_MAX)
                    {
                        st.erase({distance[i.first], i.first});
                    }
                    distance[i.first] = temp_distance;
                    st.insert({temp_distance, i.first});
                }
            }
        }
        if (distance.back() == INT_MAX)
            return -1;
        return distance.back();
    }
};