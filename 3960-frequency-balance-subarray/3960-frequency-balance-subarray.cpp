class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> cnt;
            unordered_map<int,int> freq;

            int distinct = 0;

            for(int j=i;j<n;j++)
            {
                int x = nums[j];

                int old = cnt[x];

                if(old == 0)
                    distinct++;
                else
                {
                    freq[old]--;
                    if(freq[old]==0)
                        freq.erase(old);
                }

                cnt[x]++;
                freq[old+1]++;

                if(distinct==1)
                {
                    ans=max(ans,j-i+1);
                }
                else if(freq.size()==2)
                {
                    auto it=freq.begin();

                    int a=it->first;
                    it++;
                    int b=it->first;

                    if(a*2==b || b*2==a)
                        ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};