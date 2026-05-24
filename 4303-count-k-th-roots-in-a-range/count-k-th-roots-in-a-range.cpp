class Solution
{
public:
    int countKthRoots(int l, int r, int k)
    {
        int res = 0;
        int low = 0;
        int high = r;
        int l_index = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            double temp = pow(mid, k);
            if (temp <= r && temp >= l)
            {
                l_index = mid;
                high = mid - 1;
            }
            else if (temp > r)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
         low = 0;
         high = r;
        int r_index = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            double temp = pow(mid, k);
            // cout<<low<<" "<<mid<<" "<<high<<" "<<endl;
            cout<<temp<<endl;
            if (temp <= r && temp >= l)
            {
                
                r_index = mid;
                low = mid + 1;
            }
            else if (temp > r)
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        cout<<r_index<<" "<<l_index<<endl;
        if(r_index == -1 && l_index == -1) return 0;
        return r_index - l_index + 1;
    }
};