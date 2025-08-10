class Solution
{
public:
    bool answer = false;
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
    void solve(unordered_map<int, int> &freq_map, string &number)
    {
        if (answer == true)
            return;
        if (freq_map.empty())
        {
            if (isPowerOfTwo(stoi(number)))
                answer = true;
        }
        for (auto &i : freq_map)
        {
            if (i.first == 0 && number.empty())
                continue;
            number.push_back(i.first + '0');
            i.second--;
            if (i.second == 0)
            {
                freq_map.erase(i.first);
            }
            solve(freq_map, number);
            number.pop_back();
            freq_map[i.first]++;
        }
    }

    bool reorderedPowerOf2(int n)
    {
        unordered_map<int, int> freq;
        string number = to_string(n);
        for (int i = 0; i < number.size(); i++)
        {
            freq[number[i] - '0']++;
        }
        number = "";
        solve(freq, number);
        return answer;
    }
};