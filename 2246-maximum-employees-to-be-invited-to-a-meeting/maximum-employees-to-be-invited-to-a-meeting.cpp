#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int N = favorite.size();
        int longest_cycle = 0;
        vector<bool> visited(N, false);
        vector<pair<int, int>> length_2_cycles;

        // Step 1: Find the longest cycle
        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;

            int start = i, cur = i;
            unordered_set<int> cur_set;
            while (!visited[cur]) {
                visited[cur] = true;
                cur_set.insert(cur);
                cur = favorite[cur];
            }

            if (cur_set.count(cur)) {
                int length = cur_set.size();
                while (start != cur) {
                    --length;
                    start = favorite[start];
                }
                longest_cycle = max(longest_cycle, length);
                if (length == 2) {
                    length_2_cycles.push_back({cur, favorite[cur]});
                }
            }
        }

        // Step 2: Find the sum of longest non-closed chains
        unordered_map<int, vector<int>> inverted;
        for (int i = 0; i < N; ++i) {
            inverted[favorite[i]].push_back(i);
        }

        auto bfs = [&](int src, int parent) {
            deque<pair<int, int>> q;
            q.push_back({src, 0});
            int max_length = 0;

            while (!q.empty()) {
                auto [node, length] = q.front();
                q.pop_front();

                if (node == parent) continue;
                max_length = max(max_length, length);

                for (int neighbor : inverted[node]) {
                    q.push_back({neighbor, length + 1});
                }
            }
            return max_length;
        };

        int chain_sum = 0;
        for (auto [n1, n2] : length_2_cycles) {
            chain_sum += bfs(n1, n2) + bfs(n2, n1) + 2;
        }

        return max(chain_sum, longest_cycle);
    }
};
