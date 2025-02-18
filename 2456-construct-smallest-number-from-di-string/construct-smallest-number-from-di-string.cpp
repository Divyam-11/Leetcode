#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    string result;
    void func(string pattern, vector<int> &used, string &ans)
    {
        if (ans.size() == pattern.size() + 1)
        {
            result = min(result, ans);
            return;
        }
        int j = ans.size() - 1;
        bool pick = false;
        if (pattern[j] == 'I')
        {
            int num = ans.back() - '0';
            for (int i = num; i < 10; i++)
            {
                if (!used[i])
                {

                    ans.push_back(i + '0');
                    used[i] = true;
                    func(pattern, used, ans);
                    ans.pop_back();
                    used[i] = false;
                }
            }
        }
        else
        {
            int num = ans.back() - '0';
            for (int i = 1; i < num; i++)
            {
                if (!used[i])
                {

                    ans.push_back(i + '0');
                    used[i] = true;
                    func(pattern, used, ans);
                    ans.pop_back();
                    used[i] = false;
                }
            }
        }
    }

public:
    string smallestNumber(string pattern)
    {
        result = "9999999999999";

        vector<int> used(10, 0);
        for (int i = 1; i <= 9; i++)
        {
            string ans = "";
            ans.push_back(i + '0');
            used[i] = true;
            func(pattern, used, ans);
            ans.pop_back();
            used[i] = false;
        }
        return result;
    }
};
