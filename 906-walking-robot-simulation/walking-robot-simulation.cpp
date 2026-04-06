class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int res = 0;
        int a = 0;
        int b = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int ptr = 3;
        set<pair<int, int>> st;
        for (int i = 0; i < obstacles.size(); i++)
        {
            st.insert({obstacles[i][0], obstacles[i][1]});
        }
        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] < 0)
            {
                if (commands[i] == -2)
                {
                    ptr = ((ptr - 1) + 4) % 4;
                }
                if (commands[i] == -1)
                {
                    ptr = (ptr + 1) % 4;
                }
            }
            else
            {
                int x = dir[ptr].first;
                int y = dir[ptr].second;
                int k = commands[i];
                while (k)
                {
                    int temp_i = a + x * 1;
                    int temp_j = b + y * 1;
                    if (st.find({temp_i, temp_j}) != st.end())
                    {
                        break;
                    }
                    a = temp_i;
                    b = temp_j;
                    
                    
                    res = max(res, a * a + b * b);
                    k--;
                }
               
            
            }
        }
        return res;
    }
};