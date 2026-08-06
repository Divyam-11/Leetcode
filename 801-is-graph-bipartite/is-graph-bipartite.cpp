class Solution
{
public:
    bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &colors)
    {
        if (colors[node] != -1)
        {
            return colors[node] == color;
        }
        colors[node] = color;
        for (auto it : graph[node])
        {
            if (dfs(it, !color, graph, colors) == false)
                return false;
        }
        return true;
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