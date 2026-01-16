class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        int src = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int l = edges[i][2];
            adj[u].push_back({v, l});
            adj[v].push_back({u, l});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
        vector<int> distance(adj.size());
        for (int i = 0; i < adj.size(); i++)
        {
            distance[i] = INT_MAX;
        }
        distance[src] = 0;
        st.push({0, src});
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();

            int dis = temp.first;
            int node = temp.second;

            if (dis > distance[node])
                continue;

            if (dis >= disappear[node])
                continue;

            for (auto &i : adj[node])
            {
                int v = i.first;
                int w = i.second;
                int temp_distance = dis + w;

                if (temp_distance < disappear[v] && temp_distance < distance[v])
                {
                    distance[v] = temp_distance;
                    st.push({temp_distance, v});
                }
            }
        }
        for (int i = 0; i < distance.size(); i++)
        {
            if (distance[i] == INT_MAX)
                distance[i] = -1;
        }
        return distance;
    }
};