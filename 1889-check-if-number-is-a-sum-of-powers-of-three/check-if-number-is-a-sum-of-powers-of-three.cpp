class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {    
            int temp = n % 3;
            n = n / 3;
            
            if (temp == 2){
                return false;
            }
        }
        
        return true;
    }
};