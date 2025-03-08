class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int result = k;
        int white_count = 0;
        for (int i = 0; i < k; i++)
        {   
            if(blocks[i] == 'W')
            white_count++;
        }
        
        result = min(result,white_count);
        for (int i = k; i < blocks.size(); i++)
        {
            if (blocks[i] == 'W')
                white_count++;
            if (blocks[i - k] == 'W')
                white_count--;
            result = min(result, white_count);
        }
        return result;
    }
};