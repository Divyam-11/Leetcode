class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> toposort;
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> inDegree(numCourses);
        for (int i = 0; i < adjList.size(); i++) {
            for (int j = 0; j < adjList[i].size(); j++) {
                inDegree[adjList[i][j]]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            toposort.push_back(temp);
            for (int i = 0; i < adjList[temp].size(); i++) {
                inDegree[adjList[temp][i]]--;
                if (inDegree[adjList[temp][i]] == 0) {
                    q.push(adjList[temp][i]);
                }
            }
        }
        if (toposort.size() == numCourses)
            return toposort;
        return {};
    }
};