class Solution
{
public:
    bool isPrime(int x)
    {   
        cout<<x<<endl;
        for (int d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
                return false;
        }
        cout<<(x>=2)<<endl;
        return x >= 2;
    }
    bool completePrime(int num)
    {
        string number = to_string(num);
        string temp;
        for (int i = 0; i < number.size(); i++)
        {
            temp.push_back(number[i]);
            if (!isPrime(stoi(temp)))
            {
                return false;
            }
        }
        temp.clear();
        for(int i = number.size() - 1; i >=0 ;i--){

            temp = number[i] + temp;
            if(!isPrime(stoi(temp))) return false;

        }
        return true;
    }
};