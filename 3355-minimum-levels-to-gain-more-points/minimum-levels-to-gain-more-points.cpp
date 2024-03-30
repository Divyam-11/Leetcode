class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total_points = 0;
        for (int i = 0; i < possible.size(); i++) {
            total_points += possible[i] == 1 ? 1 : -1;
        }

        int a_points = 0;
        int b_points = total_points; // Initially, Bob has all the points
        for (int i = 0; i + 1< possible.size(); i++) {
            if (possible[i] == 1) {
                a_points++;
            } else {
                a_points--;
            }
            b_points = total_points - a_points;
            if (a_points > b_points) {
                return i + 1;
            }
        }

        return -1;
    }
};
