class Solution
{
public:
    bool canPlace(int mid,int d ,vector<int> & start){
        long long  prev=start[0];
        for(int i=1 ; i<start.size(); i++){
            long long int next=max(prev+mid, static_cast<long long>(start[i]));
            if (next > start[i] + d) { 
                return false;
            }
            prev=next;
        }
        return true;
    }
    int maxPossibleScore(vector<int> &start, int d)
    {
        long long ans = 0;
        sort(start.begin(), start.end());

        long long low = 0;
        long long high = start.back() + d - start[0];
        while (low <= high)
        {
            int mid = low - (low - high) / 2;
            if (canPlace(mid, d, start))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};