class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxx(n + 1, 0);
        vector<int> minx(n + 1, n + 1);
        vector<int> maxy(n + 1, 0);
        vector<int> miny(n + 1, n + 1);
        for (int i = 0; i < buildings.size(); i++) {
            maxx[buildings[i][1]] = max(maxx[buildings[i][1]], buildings[i][0]);
            minx[buildings[i][1]] = min(minx[buildings[i][1]], buildings[i][0]);
            maxy[buildings[i][0]] = max(maxy[buildings[i][0]], buildings[i][1]);
            miny[buildings[i][0]] = min(miny[buildings[i][0]], buildings[i][1]);
        }
        int ans = 0;
        for (auto x: buildings) {
            if (x[0] < maxx[x[1]] && x[0] > minx[x[1]] && x[1] < maxy[x[0]] && x[1] > miny[x[0]]) {
                ans++;
            }
        }
        return ans;

    }
};