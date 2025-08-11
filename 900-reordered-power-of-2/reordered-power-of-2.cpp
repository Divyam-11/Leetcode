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
        vector<int> keys;
        for (auto &p : freq_map) keys.push_back(p.first); // store keys first

        for (int digit : keys) {
            if (digit == 0 && number.empty()) continue; // avoid leading zero

            number.push_back(digit + '0');
            if (--freq_map[digit] == 0) {
                freq_map.erase(digit);
            }

            solve(freq_map, number);

            // backtrack
            freq_map[digit]++;
            number.pop_back();
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