class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int m = restrictions.size();

        if(m == 0){
            return n-1;
        }
        sort(restrictions.begin(), restrictions.end());

        restrictions[0][1] = min(restrictions[0][1], restrictions[0][0] - 1);

        for(int i=1; i<m; i++){
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }

        for(int i=m-2; i>=0; i--){
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }

        int maxi = (0 + restrictions[0][1] + (restrictions[0][0] - 1))/2;

        for(int i=1; i<m; i++){
            maxi = max(maxi, (restrictions[i-1][1] + restrictions[i][1] + (restrictions[i][0] - restrictions[i-1][0]))/2);
        }

        maxi = max(maxi, (n - restrictions[m-1][0] + restrictions[m-1][1]));

        return maxi;


    }
};