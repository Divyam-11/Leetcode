class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string res;
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            if (res.size() > 1 && res[res.size() - 1] == temp.second && res[res.size() - 2] == temp.second)
            {
                if (pq.empty()) break;
                auto temp2 = pq.top();
                pq.pop();
                res += temp2.second;
                temp2.first--;
                if (temp2.first>0)
                    pq.push(temp2);
            
            pq.push(temp);
            }
            else
            {
                res += temp.second;
                temp.first--;
                if (temp.first>0)
                {
                    pq.push(temp);
                }
            }
        }
        return res;
    }
};