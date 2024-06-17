class Solution {
private:
int mySqrt(int x) {
        int low = 0;
        int high = x;
        while(low<=high){
            long long mid = (low+high)/2;
            if(mid*mid>x){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
public:
    bool judgeSquareSum(int c) {
        long  high = mySqrt(c);
        long  low = 0;
        while(low<=high){
            if(low*low + high*high == c) return true;
            else if(low*low + high*high < c){
                low++;
            }
            else{
                high --;
            }
        }
    return false;
    }
};