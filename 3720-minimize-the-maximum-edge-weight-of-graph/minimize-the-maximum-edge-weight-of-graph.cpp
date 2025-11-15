class Solution
{
public:
    int prims(int n, vector<vector<pair<int, int>>> &adjList)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n);
        pq.push({0, 0});
        int mx_wt = -1;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (visited[node] == 1)
                continue;
            mx_wt = max(mx_wt, wt);
            visited[node] = 1;
            for (auto it : adjList[node])
            {
                int temp_node = it.first;
                int temp_wt = it.second;
                if (!visited[temp_node])
                {
                    pq.push({temp_wt, temp_node});
                }
            }
        }
        for(auto i : visited){

            if(i == 0) return -1;
        }
        return mx_wt;
    }
    int minMaxWeight(int n, vector<vector<int>> &edges, int threshold)
    {
        vector<vector<pair<int, int>>> adjlist(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adjlist[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int res = prims(n, adjlist);
      
        return res;
    }
};