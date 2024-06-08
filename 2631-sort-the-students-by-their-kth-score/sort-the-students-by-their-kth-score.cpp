#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        for(int i = 0 ; i < n - 1; i++) {
            for(int j = 0 ; j < n - i - 1; j++) {
                if(score[j][k] < score[j+1][k]) {
                    vector<int> temp = score[j];
                    score[j] = score[j+1];
                    score[j+1] = temp;
                }
            }
        }
        return score;
    }
};
