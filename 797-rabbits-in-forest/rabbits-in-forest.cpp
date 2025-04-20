class Solution {
public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> count_map;
        int total = 0;

        for (int ans : answers) {
            if (count_map[ans] == 0) {
                total += ans + 1;  // new group starts
                count_map[ans] = ans;
            } else {
                count_map[ans]--;  // fill existing group
            }
        }

        return total;
    }
};
