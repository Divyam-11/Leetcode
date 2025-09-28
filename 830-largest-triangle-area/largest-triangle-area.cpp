class Solution {
public:
    
double largestTriangleArea(vector<vector<int>>& p) {
    double res = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                double area = 0.5 * abs(p[i][0] * p[j][1] +
                                        p[j][0] * p[k][1] +
                                        p[k][0] * p[i][1] -
                                        p[j][0] * p[i][1] -
                                        p[k][0] * p[j][1] -
                                        p[i][0] * p[k][1]);
                res = max(res, area);
            }
        }
    }
    return res;
}

};