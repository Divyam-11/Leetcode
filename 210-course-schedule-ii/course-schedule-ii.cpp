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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[v].push_back(u);
        }
        vector<int> topo = topoSort(numCourses, adjList);
        if(topo.size() != numCourses) return {};
        return topo;
    }
};