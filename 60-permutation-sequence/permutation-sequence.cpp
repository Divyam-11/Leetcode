class Solution {
public:
    string ans;

    void solve(int index, int n, int &count, int k, string &temp, vector<bool> &used) {
        if (!ans.empty()) return;

        if (index > n) {
            count++;
            if (count == k)
                ans = temp;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;

            used[i] = true;
            temp.push_back(i + '0');
            solve(index + 1, n, count, k, temp, used);
            used[i] = false;
            temp.pop_back();
        }
    }

    string getPermutation(int n, int k) {
        vector<bool> used(n + 1, false);
        string temp;
        int count = 0;
        solve(1, n, count, k, temp, used);
        return ans;
    }
};