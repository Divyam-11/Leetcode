class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int k;
        
        
        int r = 1000000000;
        int result = r;
        while(l<=r){

            k = (l+r) /2;
            long long hours = 0;
            for(auto p : piles){
               hours += ceil(1.0 * p / k);  // This calculates the ceiling of p/k
            }
            if(hours<=h){
                result = min(result,k);
                 r = k -1;
            }
            else l = k+1;
        }
        return result;

    }
};