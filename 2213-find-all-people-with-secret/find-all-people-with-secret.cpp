class Solution {
public:
    typedef pair<int,int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        for (auto &m : meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }

        vector<int> earlySecretTime(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;

        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            if (time > earlySecretTime[person]) continue;

            for (auto &[nextPerson, t] : adj[person]) {
                if (t >= time && earlySecretTime[nextPerson] > t) {
                    earlySecretTime[nextPerson] = t;
                    pq.push({t, nextPerson});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (earlySecretTime[i] != INT_MAX)
                result.push_back(i);
        }
        return result;
    }
};
