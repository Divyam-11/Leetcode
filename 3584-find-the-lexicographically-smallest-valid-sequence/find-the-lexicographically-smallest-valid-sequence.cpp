class Solution {
public:
vector<int> validSequence(const string &w1, const string &w2) {
    int sz1 = w1.size(), sz2 = w2.size(), wild = 1;
    vector<int> dp(w1.size() + 1), res;
    for (int i = sz1 - 1, j = sz2 - 1; i >= 0; --i) {
        dp[i] = dp[i + 1] + (j >= 0 && w1[i] == w2[j]);
        j -= j >= 0 && w1[i] == w2[j]; 
    }
    bool found = false;
    for (int i = 0; i < sz1 && res.size() < sz2; ++i) {
        if (w1[i] == w2[res.size()])
            res.push_back(i);
        else if (wild && res.size() + wild + dp[i + 1] >= sz2) {
            --wild;
            res.push_back(i);
        }
    }
    return res.size() == sz2 ? res : vector<int>{};
}
};