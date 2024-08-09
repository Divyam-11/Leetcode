class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<vector<int>> adjList(graph.size());
        vector<int> inDegree(graph.size());
        for (int i = 0; i < graph.size(); i++)
        {
            for (auto it : graph[i])
            {
                adjList[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < graph.size(); i++)
        {

            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjList[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};