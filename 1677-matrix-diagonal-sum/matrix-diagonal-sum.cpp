class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0 ;
        for(int i = 0 ;  i<mat.size();i++){
            result+=mat[i][i];
        }
    int i,j;
    i = 0, j = mat.size()-1;
    while(i<mat.size(),j>=0){
        result+=mat[i][j];
        i++;
        j--;
    }
    if(mat.size() %2 == 0) return result;
    else {
        result -=mat[mat.size()/2][mat.size()/2];
    }
    return result;
}
};