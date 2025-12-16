#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fut, pre;
    vector<vector<int>> adj;
    int bud;

    vector<vector<int>> dp[2];
    vector<bool> calculated[2];

    vector<int> ans(bool taken, int v) {
        if (calculated[taken][v]) {
            return dp[taken][v];
        }

        vector<int> finalAns(bud + 1, INT_MIN);
        int numchild = adj[v].size();
        int curprice = pre[v];
        if (taken) curprice /= 2;

        if (curprice <= bud) {
            vector<vector<int>> childans(numchild);
            for (int i = 0; i < numchild; i++) {
                childans[i] = ans(true, adj[v][i]);
            }

            vector<int> curAns(bud + 1, INT_MIN);
            curAns[curprice] = fut[v];

            for (int i = 0; i < numchild; i++) {
                vector<int> newans = curAns;
                for (int j = 0; j <= bud; j++) {
                    if (childans[i][j] == INT_MIN) continue;
                    for (int k = 0; k <= bud; k++) {
                        if (curAns[k] == INT_MIN) continue;
                        if (k + j <= bud) {
                            newans[k + j] = max(newans[k + j],
                                                 curAns[k] + childans[i][j]);
                        }
                    }
                }
                curAns = newans;
            }

            for (int i = 0; i <= bud; i++) {
                finalAns[i] = max(finalAns[i], curAns[i]);
            }
        }

        {
            vector<vector<int>> childans(numchild);
            for (int i = 0; i < numchild; i++) {
                childans[i] = ans(false, adj[v][i]);
            }

            vector<int> curAns(bud + 1, INT_MIN);
            curAns[0] = 0;

            for (int i = 0; i < numchild; i++) {
                vector<int> newans = curAns;
                for (int j = 0; j <= bud; j++) {
                    if (childans[i][j] == INT_MIN) continue;
                    for (int k = 0; k <= bud; k++) {
                        if (curAns[k] == INT_MIN) continue;
                        if (k + j <= bud) {
                            newans[k + j] = max(newans[k + j],
                                                 curAns[k] + childans[i][j]);
                        }
                    }
                }
                curAns = newans;
            }

            for (int i = 0; i <= bud; i++) {
                finalAns[i] = max(finalAns[i], curAns[i]);
            }
        }

        calculated[taken][v] = true;
        dp[taken][v] = finalAns;
        return finalAns;
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        adj.assign(n, vector<int>());
        fut = future;
        pre = present;
        bud = budget;

        for (auto& edge : hierarchy) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }

        for (int i = 0; i < 2; i++) {
            dp[i].assign(n, vector<int>(budget + 1, INT_MIN));
            calculated[i].assign(n, false);
        }

        vector<int> finalAns = ans(false, 0);
        int res = 0;
        for (int i = 0; i <= bud; i++) {
            if (finalAns[i] != INT_MIN) {
                res = max(res, finalAns[i] - i);
            }
        }
        return res;
    }
};
