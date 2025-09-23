class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1;
        vector<int> v2;
        int temp = 0;
        for (int i = 0; i < version1.size(); i++)
        {
            if (version1[i] == '.')
            {
                v1.push_back(temp);
                temp = 0;
            }
            else
            {
                temp *= 10;
                temp += version1[i] - '0';
            }
        }
        v1.push_back(temp);
        temp = 0;
        for (int i = 0; i < version2.size(); i++)
        {
            if (version2[i] == '.')
            {
                v2.push_back(temp);
                temp = 0;
            }
            else
            {
                temp *= 10;
                temp += version2[i] - '0';
            }
        }
        v2.push_back(temp);
        for (int i = 0; i < max(v2.size(), v1.size()); i++)
        {
            int var1 = 0;
            int var2 = 0;
            if (i < v1.size())
            {
                var1 = v1[i];
            }
            if (i < v2.size())
            {
                var2 = v2[i];
            }
            if (var1 < var2)
                return -1;
            if (var1 > var2)
                return 1;
        }
        return 0;
    }
};