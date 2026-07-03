class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);
        int mxCost = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            indegree[v]++;
            mxCost = max(mxCost, c);
        }

        // Topological order
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, c] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) {
            const long long INF = (1LL << 60);
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, c] : adj[u]) {
                    if (c < limit)
                        continue;
                    if (v != 0 && v != n - 1 && !online[v])
                        continue;

                    if (dist[u] + c < dist[v])
                        dist[v] = dist[u] + c;
                }
            }

            return dist[n - 1] <= k;
        };

        if (!check(0))
            return -1;

        int lo = 0, hi = mxCost;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo;
    }
};