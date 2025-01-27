class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, int found)
    {
        if (node == found)
            return true;
        visited[node] = 1;
        for (auto i : adjList[node])
        {
            if (!visited[i])
            {
                if (dfs(i, adjList, visited, found) == true)
                    return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> answer(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            vector<int> visited(numCourses);
            answer[i] = dfs(queries[i][0], adjList, visited, queries[i][1]);
        }
        return answer;
    }
};