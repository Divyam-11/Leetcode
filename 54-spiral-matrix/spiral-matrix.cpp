class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int min_r = 0;
    int min_c = 0;
    int max_c = matrix[0].size()-1;
    int max_r = matrix.size()-1;
    while(min_r<=max_r && max_c>=min_c){
        for(int i = min_c;i<=max_c;i++){
            result.push_back(matrix[min_r][i]);

        }
        min_r++;
        for(int i = min_r ;i<=max_r;i++){
            result.push_back(matrix[i][max_c]);
        }
        max_c--;
            if (min_r <= max_r) {
                for (int i = max_c; i >= min_c; i--) {
                    result.push_back(matrix[max_r][i]);
                }
                max_r--;
            }

            // Traverse up
            if (min_c <= max_c) {
                for (int i = max_r; i >= min_r; i--) {
                    result.push_back(matrix[i][min_c]);
                }
    min_c++;

    }
    }
    return result;
    }

};