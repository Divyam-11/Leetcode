class Solution
{
public:
    vector<int> topoSort(int n, vector<vector<int>> &adjList)
    {
        vector<int> inDegree(n);
        for (int i = 0; i < adjList.size(); i++)
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                inDegree[adjList[i][j]]++;
            }
        }
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto it : adjList[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<vector<int>> adjList(graph.size());
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                int u = i;
                int v = graph[i][j];
                adjList[v].push_back(u);
            }
        }
        vector<int> topo = topoSort(graph.size(), adjList);
        sort(topo.begin(), topo.end());
        return topo;
    }
};