class Solution
{
public:
    vector<long long> dijkstra(vector<vector<pair<int, int>>> adj, int src)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> st;
        vector<long long> distance(adj.size());
        for (int i = 0; i < adj.size(); i++)
        {
            distance[i] = LLONG_MAX;
        }
        distance[src] = 0;
        st.push({0, src});
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();
            long long dis = temp.first;
            int node = temp.second;
            for (pair<int, int> &i : adj[node])
            {

                long long temp_distance = (dis + i.second);
                if (distance[i.first] > temp_distance)
                {
                    distance[i.first] = temp_distance;
                    st.push({temp_distance, i.first});
                }
            }
        }
        return distance;
    }
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<pair<int, int>>> adjList(26);
        for (int i = 0; i < original.size(); i++)
        {
            adjList[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        unordered_map<char, vector<long long>> cache;
        long long res = 0;
        for (int i = 0; i < 26; i++)
        {
            cache[i+'a'] = dijkstra(adjList, i);
        }
        // long long res = 0;
        for (int i = 0; i < source.size(); i++)
        {
            long long c = cache[source[i]][target[i] - 'a'];
            if (c == LLONG_MAX)
                return -1;
            res += c;
        }
        return res;
    }
};