class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int result = 0;
        int emptyBottles = 0;
        while (numBottles)
        {
            result += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            if (emptyBottles - numExchange >= 0)
            {
                numBottles += 1;
                emptyBottles -= numExchange;
                numExchange++;
            }
        }
        return result;
    }
};