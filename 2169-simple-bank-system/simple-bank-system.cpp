class Bank
{
public:
    vector<long long> balance;
    Bank(vector<long long> &balance)
    {
        this->balance = balance;
    }

    bool transfer(int account1, int account2, long long money)
    {
        account1--;
        account2--;
        if (account1 < 0 || account1 >= balance.size())
            return false;
        if (account2 < 0 || account2 >= balance.size())
            return false;
        if (balance[account1] < money)
            return false;
        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        account--;
        if (account < 0 || account >= balance.size())
            return false;
        balance[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        account--;
        if (account < 0 || account >= balance.size())
            return false;

        if (balance[account] < money)
            return false;
        balance[account] -= money;
        return true;
    }
};
