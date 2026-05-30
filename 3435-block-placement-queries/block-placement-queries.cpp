class Segment {
public:
    vector<int> tree;
    int n;

    Segment(int n) {
        this->n = n;
        tree.resize(4 * n, 0);
    }

    void update(int left, int right, int idx, int qIdx, int val) {
        if (left == right) {
            tree[idx] = val;
            return;
        }

        int m = left + (right - left) / 2;

        if (qIdx <= m) {
            update(left, m, 2 * idx + 1, qIdx, val);
        } else {
            update(m + 1, right, 2 * idx + 2, qIdx, val);
        }

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int left, int right, int idx, int qleft, int qright) {
        if (left >= qleft && right <= qright)
            return tree[idx];

        if (left > qright || right < qleft)
            return INT_MIN;

        int m = left + (right - left) / 2;

        int leftSub = query(left, m, 2 * idx + 1, qleft, qright);
        int rightSub = query(m + 1, right, 2 * idx + 2, qleft, qright);

        return max(leftSub, rightSub);
    }
};

class Solution {
public:
    vector<int> d;
    int maxN;
    set<int> positions;

    int lb(int tar) {
        auto it = positions.upper_bound(tar);
        if (it == positions.begin()) return -1;
        --it;
        return *it;
    }

    int ub(int tar) {
        auto it = positions.lower_bound(tar);
        if (it == positions.end()) return -1;
        return *it;
    }

    vector<bool> getResults(vector<vector<int>>& que) {
        maxN = min(50000, (int)que.size() * 3);

        d.assign(maxN + 1, 0);

        Segment ds(maxN);

        vector<bool> ans;

        for (auto &q : que) {
            int type = q[0];

            if (type == 1) {
                int pos = q[1];

                int left = lb(pos);
                int right = ub(pos);

                if (left != -1) {
                    d[left] = pos - left;
                    ds.update(0, maxN + 1, 0, left, d[left]);
                }

                if (right != -1) {
                    d[pos] = right - pos;
                } else {
                    d[pos] = INT_MAX;
                }

                ds.update(0, maxN + 1, 0, pos, d[pos]);
                positions.insert(pos);
            }
            else {
                int pos = q[1];
                int sz = q[2];

                int prev = lb(pos);

                if (prev == -1) {
                    ans.push_back(pos >= sz);
                    continue;
                }

                int mn = *positions.begin();

                if (min(mn, pos) >= sz) {
                    ans.push_back(true);
                    continue;
                }

                int p = prev;

                if (pos - p >= sz) {
                    ans.push_back(true);
                    continue;
                }

                int mx = ds.query(0, maxN + 1, 0, 0, p - 1);

                if (mx == 0) {
                    ans.push_back(p >= sz);
                    continue;
                }

                ans.push_back(mx >= sz);
            }
        }

        return ans;
    }
};