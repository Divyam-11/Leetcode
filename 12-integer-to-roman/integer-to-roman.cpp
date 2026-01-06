class Solution
{
public:
    string intToRoman(int num)
    {   
        string res ="";
        string nums = to_string(num);
        vector<vector<pair<int, int>>> builder = {
            {},
            {{0, 1}},
            {{0, 2}},
            {{0, 3}},
            {{0, 1}, {1, 1}},
            {{1, 1}},
            {{1, 1}, {0, 1}},
            {{1, 1}, {0, 2}},
            {{1, 1}, {0, 3}},
            {{0, 1}, {2, 1}}};
        unordered_map<int, string> mp;
        mp[0] = "IVX";
        mp[1] = "XLC";
        mp[2] = "CDM";
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = nums.size() - i - 1;
            if (idx == 3)
            {
                res += string( nums[i]-'0','M');
            }
            else
            {
                for (auto p : builder[nums[i] - '0'])
            
                {   cout<<mp[idx][p.first];
                    cout<<p.second<<endl;
                    string temp = string(p.second,mp[idx][p.first]);
                    
                    res += temp;
                }
            }
        }
        return res;
    }
};