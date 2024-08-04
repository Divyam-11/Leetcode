class Solution
{
    bool hasCycle(int index, vector<vector<int>> &prerequisites, vector<int> &visited, vector<int> &path_visited)
    {
        visited[index] = 1;
        path_visited[index] = 1;

        for (auto it : prerequisites[index])
        {
            if (!visited[it])
            {
                if (hasCycle(it, prerequisites, visited, path_visited))
                    return true;
            }
            else if (path_visited[it])
            {
                return true;
            }
        }
        path_visited[index] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        for (const auto &prereq : prerequisites)
        {
            adjList[prereq[1]].push_back(prereq[0]);
        }
        vector<int> visited(numCourses, 0);      // Initialize with numCourses elements, all set to 0
        vector<int> path_visited(numCourses, 0); // Initialize with numCourses elements, all set to 0

        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i])
            {
                if (hasCycle(i, adjList, visited, path_visited))
                    return false;
            }
        }

        return true;
    }
};