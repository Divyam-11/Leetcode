class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int placed = 0;
        int total = fruits.size();
        for (int i = 0; i < fruits.size(); i++)
        {
            for (int j = 0; j < baskets.size(); j++)
            {
                if (baskets[j] >= fruits[i])
                {   cout<<i<<"" <<j<<endl;
                    placed++;
                    baskets[j] *= -1;
                    break;
                }
            }
        }
        return total - placed;
    }
};