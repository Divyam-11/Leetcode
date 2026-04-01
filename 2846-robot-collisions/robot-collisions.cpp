#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        vector<vector<int>> nums;
        vector<pair<int, int>> res;
        for (int i = 0; i < positions.size(); i++)
        {
            nums.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> st;
        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i][2] == 'L')
            {
                int hp = nums[i][1];
                while (!st.empty() && hp > 0)
                {
                    int hp_e = st.back()[1];
                    if (hp_e < hp)
                    {
                        st.pop_back();
                        hp--;
                    }
                    else if (hp_e == hp)
                    {
                        hp = 0;
                        st.pop_back();
                    }
                    else
                    {
                        hp = 0;
                        st[st.size() - 1][1]--;
                    }
                }
                if (hp != 0)
                {
                    res.push_back({nums[i][3], hp});
                }
            }
            else if (nums[i][2] == 'R')
            {
                st.push_back(nums[i]);
            }
        }
        for (int i = 0; i < st.size(); i++)
        {
            res.push_back({st[i][3], st[i][1]});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for (int i = 0; i < res.size(); i++)
        {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};
