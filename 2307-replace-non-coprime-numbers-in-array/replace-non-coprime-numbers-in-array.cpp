class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {

        vector<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            while (!st.empty() && __gcd(st.back(), a) != 1)
            {
                a = lcm(st.back(), a);
                st.pop_back();
            }
            st.push_back(a);
        }
        return st;
    }
};