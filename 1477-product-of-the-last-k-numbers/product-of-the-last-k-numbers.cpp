class ProductOfNumbers
{
public:
    vector<int> prefixSum = {1};

    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
        {
            prefixSum = {1};
        }
        else
            prefixSum.push_back(prefixSum.back() * num);
    }

    int getProduct(int k)
    {
        if (k >=prefixSum.size())
            return 0;
        else
            return prefixSum.back() / prefixSum[prefixSum.size() - k-1];
    }
};