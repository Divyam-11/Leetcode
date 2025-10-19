class Solution
{
public:
    int longestBalanced(string s)
    {

        int n = s.size();
        int maxi = 1;

        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                len++;
            }
            else
            {
                maxi = max(maxi, len);
                len = 1;
            }
        }
        maxi = max(maxi, len);


        {
            int sum = 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'a')
                {
                    sum += 1;
                }
                else if (s[i] == 'b')
                {
                    sum -= 1;
                }
                else
                {
                    mp.clear();
                    mp[0] = i;
                    sum = 0;
                    continue;
                }

                if (mp.find(sum) != mp.end())
                {
                    maxi = max(maxi, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }

   
        {
            int sum = 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'b')
                {
                    sum += 1;
                }
                else if (s[i] == 'c')
                {
                    sum -= 1;
                }
                else
                {
                    mp.clear();
                    mp[0] = i;
                    sum = 0;
                    continue;
                }

                if (mp.find(sum) != mp.end())
                {
                    maxi = max(maxi, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }


        {
            int sum = 0;
            unordered_map<int, int> mp;
            mp[0] = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'a')
                {
                    sum += 1;
                }
                else if (s[i] == 'c')
                {
                    sum -= 1;
                }
                else
                {
                    mp.clear();
                    mp[0] = i;
                    sum = 0;
                    continue;
                }

                if (mp.find(sum) != mp.end())
                {
                    maxi = max(maxi, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }

        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> count(3, 0);
        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++;

            int countAB = count[0] - count[1];
            int countAC = count[0] - count[2];

            if (mp.find({countAB, countAC}) != mp.end())
            {
                maxi = max(maxi, i - mp[{countAB, countAC}]);
            }
            else
            {
                mp[{countAB, countAC}] = i;
            }
        }

        return maxi;
    }
};
