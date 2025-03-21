class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> st(begin(supplies), end(supplies));
        vector<string> result;
        int n = recipes.size();
        vector<int> inDegree(n);
        unordered_map<string, vector<int>> adjList;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < ingredients[i].size(); j++)
            {
                if (!st.count(ingredients[i][j]))
                {
                    adjList[ingredients[i][j]].push_back(i);
                    inDegree[i]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while ((!q.empty()))
        {
            int node = q.front();
            q.pop();

            result.push_back(recipes[node]);

            for (int &idx : adjList[recipes[node]])
            {
                inDegree[idx]--;
                if (inDegree[idx] == 0)
                {
                    q.push(idx);
                }
            }
            
        }
    return result;
    }
    };