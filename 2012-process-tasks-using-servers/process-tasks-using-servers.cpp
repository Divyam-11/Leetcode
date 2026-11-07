using T = tuple<long long, int, int>;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<T, vector<T>, greater<T>> pqA;
        priority_queue<T, vector<T>, greater<T>> pqB;

        vector<int> ans(tasks.size());

        for (int i = 0; i < servers.size(); i++) {
            pqA.emplace(servers[i], i, 0);
        }

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            if (pqA.empty()) {
                time = max(time, get<0>(pqB.top()));
            }

            while (!pqB.empty() && get<0>(pqB.top()) <= time) {
                auto [t, w, idx] = pqB.top();
                pqB.pop();
                pqA.emplace(w, idx, 0);
            }

            auto [w, idx, dummy] = pqA.top();
            pqA.pop();

            ans[i] = idx;

            pqB.emplace(time + tasks[i], w, idx);
        }

        return ans;
    }
};