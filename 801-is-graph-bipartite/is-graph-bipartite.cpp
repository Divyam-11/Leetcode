class Solution
{
public:
    bool canPlace(int node, vector<vector<int>> &graph, int color, vector<int> &colors)
    {
        for (auto &it : graph[node])
        {
            if (colors[it] == color)
                return false;
        }
        return true;
    }
    bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &colors)
    {   
        if(colors[node] != -1) return true;
        if (canPlace(node, graph, color, colors))
        {
            colors[node] = color;
            for (auto it : graph[node])
            {
                if (!dfs(it, !color, graph, colors))
                    return false;
            }
            return true;
        }

        return false;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {

        int m = graph.size();
        vector<int> colors(m, -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (colors[i] == -1)
            {
                if (!dfs(i, 0, graph, colors))
                    return false;
            }
        }
        return true;
    }
};