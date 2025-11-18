class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int ptr = 0;
        while (ptr < bits.size() - 1)
        {
            if (bits[ptr] == 1)
            {
                ptr += 2;
            }
            else
            {
                ptr++;
            }
        }
        return ptr == bits.size() - 1;
    }
};