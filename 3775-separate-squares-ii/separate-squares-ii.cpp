class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<array<long long,4>> events;

        for (auto &sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.push_back({y,  1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
        }

        sort(events.begin(), events.end());

        vector<pair<long long,long long>> xs;
        long long prev_y = events[0][0];
        long double total = 0.0;

        vector<tuple<long long,long long,long long>> areas;

        auto union_len = [&](vector<pair<long long,long long>>& intervals) {
            sort(intervals.begin(), intervals.end());
            long long res = 0;
            long long end = LLONG_MIN;

            for (auto &p : intervals) {
                long long a = p.first, b = p.second;
                if (a > end) {
                    res += (b - a);
                    end = b;
                } else if (b > end) {
                    res += (b - end);
                    end = b;
                }
            }
            return res;
        };

        for (auto &e : events) {
            long long y = e[0];
            int type = e[1];
            long long x1 = e[2], x2 = e[3];

            if (y > prev_y && !xs.empty()) {
                long long h = y - prev_y;
                long long w = union_len(xs);
                areas.emplace_back(prev_y, h, w);
                total += (long double)h * w;
            }

            if (type == 1) {
                xs.emplace_back(x1, x2);
            } else {
                xs.erase(find(xs.begin(), xs.end(), make_pair(x1, x2)));
            }

            prev_y = y;
        }

        long double half = total / 2.0;
        long double acc = 0.0;

        for (auto &[y, h, w] : areas) {
            long double area = (long double)h * w;
            if (acc + area >= half) {
                return (double)(y + (half - acc) / w);
            }
            acc += area;
        }

        return 0.0;
    }
};
