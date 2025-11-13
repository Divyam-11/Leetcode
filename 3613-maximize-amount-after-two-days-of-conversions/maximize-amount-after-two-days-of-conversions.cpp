class Solution
{
public:
    double ans = 1;
    void dfs1(int node, vector<vector<pair<int, double>>> &adjList2, unordered_map<string, int> &mp, double value, vector<int> &visited, vector<double> &rates)
    {
        if (visited[node])
            return;
        visited[node] = 1;
        for (auto i : adjList2[node])
        {
            rates[i.first] = value * i.second;
            dfs1(i.first, adjList2, mp, value * i.second, visited, rates);
        }
    }
    void dfs2(int node, vector<vector<pair<int, double>>> &adjList2, unordered_map<string, int> &mp, double value, vector<int> &visited, vector<double> &rates)
    {
        if (visited[node])
            return;
        visited[node] = 1;
        ans = max(ans, value * (1 / rates[node]));
        for (auto i : adjList2[node])
        {
            dfs2(i.first, adjList2, mp, value * i.second, visited, rates);
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>> &pairs1, vector<double> &rates1, vector<vector<string>> &pairs2, vector<double> &rates2)
    {
        set<string> st;
        st.insert(initialCurrency);
        for (int i = 0; i < pairs1.size(); i++)
        {
            st.insert(pairs1[i][0]);
            st.insert(pairs1[i][1]);
        }
        for (int i = 0; i < pairs2.size(); i++)
        {
            st.insert(pairs2[i][0]);
            st.insert(pairs2[i][1]);
        }
        int ptr = 0;
        unordered_map<string, int> mp;
        for (auto i : st)
        {
            mp[i] = ptr;
            ptr++;
        }
        vector<vector<pair<int, double>>> adjList1(st.size());
        vector<vector<pair<int, double>>> adjList2(st.size());
        for (int i = 0; i < pairs1.size(); i++)
        {
            adjList1[mp[pairs1[i][0]]].push_back({mp[pairs1[i][1]], rates1[i]});
            adjList1[mp[pairs1[i][1]]].push_back({mp[pairs1[i][0]], 1 / rates1[i]});
        }
        for (int i = 0; i < pairs2.size(); i++)
        {
            adjList2[mp[pairs2[i][0]]].push_back({mp[pairs2[i][1]], rates2[i]});
            adjList2[mp[pairs2[i][1]]].push_back({mp[pairs2[i][0]], 1 / rates2[i]});
        }
        vector<int> visited(adjList1.size());
        vector<double> rates(adjList1.size(),-1);
        rates[mp[initialCurrency]] = 1;
        dfs1(mp[initialCurrency], adjList2, mp, 1, visited, rates);
        vector<int> visited1(adjList1.size());
        dfs2(mp[initialCurrency], adjList1, mp, 1, visited1, rates);
        return ans;
    }
};