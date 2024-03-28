class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),points.end());
        int n = points.size();
        int result = n;
        vector<int> prev = points[0];
        for(int i = 1 ; i<n;i++){
          vector<int> curr = points[i];
          if(curr[0] <=prev[1]){
            result--;
            prev = {curr[0],min(curr[1],prev[1])};
          }
          else prev = curr;
        }
        return result;
    }
};