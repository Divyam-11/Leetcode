
class Solution {
public:
    vector<int> closest = vector<int>(26, -1);

    void fun(int node, vector<vector<int>>& adj,
             vector<int>& par, string& s) {

        int c = closest[s[node]-'a'];
        closest[s[node]-'a']=node;
        for(int nbr: adj[node]){
            if(par[nbr]!=node)continue;
            fun(nbr, adj, par, s);
        }
        if(c!=-1){
            par[node]=c;
        }
        closest[s[node]-'a']=c;
    }

    int precomp(int node, vector<vector<int>>& adj,
                vector<int>& ans, vector<int>& par, string& s) {

        int children = 1;

        for (int nbr : adj[node]) {
            children += precomp(nbr, adj, ans, par, s);
        }

        ans[node] = children;

        return children;
    }

    vector<int> findSubtreeSizes(vector<int>& par, string s) {
        int n = par.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[par[i]].push_back(i);
        }

        fun(0, adj, par, s);

        adj.assign(n, {});

        for (int i = 1; i < n; i++) {
            adj[par[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        precomp(0, adj, ans, par, s);

        return ans;
    }
};