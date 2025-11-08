class Solution
{
public:
    // return k edges reach
    int bfs(vector<vector<int>> &adjList, int node, int k, vector<int> &visited)
    {   
        if(k<0) return 0;
        queue<pair<int, int>> q;

        // {node,edge_count}
        q.push({node, 0});
        visited[node] = 1;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int temp_node = temp.first;
            int temp_edges = temp.second;
            visited[temp_node] = 1;
            for (auto i : adjList[temp_node])
            {
                if (!visited[i] && temp_edges + 1 <= k)
                {
                    q.push({i, temp_edges + 1});
                }
            }
        }
        int res = 0;
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i])
                res++;
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adjList1(n);
        vector<vector<int>> adjList2(m);
        for (int i = 0; i < edges1.size(); i++)
        {
            int u = edges1[i][0];
            int v = edges1[i][1];
            adjList1[u].push_back(v);
            adjList1[v].push_back(u);
        }
        for (int i = 0; i < edges2.size(); i++)
        {
            int u = edges2[i][0];
            int v = edges2[i][1];
            adjList2[v].push_back(u);
            adjList2[u].push_back(v);
        }
        int edges2_max_boost = 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> t(m);
            int temp = bfs(adjList2, i, k - 1, t);
            edges2_max_boost = max(temp, edges2_max_boost);
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> t(n);
            int temp = bfs(adjList1, i, k, t);
            answer[i] = temp + edges2_max_boost;
        }
        return answer;
    }
};