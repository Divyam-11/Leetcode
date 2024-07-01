class Solution
{
private:
    void dfs(int node,vector<vector<int>> &isConnected, vector<int> &visited)
    {
        visited[node] = 1;
        for (int i = 0; i < isConnected.size(); i++)
        {
        if(isConnected[node][i] == 1 && visited[i] == 0){
            dfs(i,isConnected,visited);
        }
        }

    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int count = 0;
        vector<int> visited(isConnected.size(),0);
        for(int i = 0 ; i < visited.size();i++){
            if(visited[i] == 0){
            count++;
            dfs(i,isConnected,visited);
            }
        }
        return count;
    }
};