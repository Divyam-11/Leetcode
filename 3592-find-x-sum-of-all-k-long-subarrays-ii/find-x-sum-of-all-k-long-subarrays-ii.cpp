
struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        vector<long long> res;
        set<pair<int, int>, cmp> top_x;
        set<pair<int, int>, cmp> st;
        unordered_map<int, int> mp;
        
        long long sum = 0;

        for (int i = 0; i < k; i++)
        {
            mp[nums[i]]++;
        }

        for (auto const& [value, freq] : mp)
        {
            st.insert({freq, value});
        }

        int temp = x;
        while (temp-- > 0 && !st.empty())
        {
            auto f = *st.begin();
            st.erase(f);
            top_x.insert(f);
            sum += (long long)f.first * f.second;
        }
        res.push_back(sum);

        int l = 0;
        for (int i = k; i < nums.size(); i++)
        {
            int val_l = nums[l];
            int old_freq_l = mp[val_l];
            
            mp[val_l]--; 
            int new_freq_l = mp[val_l];

            if (top_x.count({old_freq_l, val_l})) {
                top_x.erase({old_freq_l, val_l});
                sum -= (long long)old_freq_l * val_l;
            } else {
                st.erase({old_freq_l, val_l});
            }

            if (new_freq_l > 0) {
                st.insert({new_freq_l, val_l});
            }
            l++;

            int val_i = nums[i];
            int old_freq_i = mp[val_i];
            
            mp[val_i]++; 
            int new_freq_i = mp[val_i];

            if (old_freq_i > 0) {
                if (top_x.count({old_freq_i, val_i})) {
                    top_x.erase({old_freq_i, val_i});
                    sum -= (long long)old_freq_i * val_i;
                } else {
                    st.erase({old_freq_i, val_i});
                }
            }
            
            st.insert({new_freq_i, val_i});

            while (top_x.size() < x && !st.empty()) {
                auto best_st = *st.begin();
                st.erase(best_st);
                top_x.insert(best_st);
                sum += (long long)best_st.first * best_st.second;
            }

          while (!st.empty() && !top_x.empty() && cmp()(*st.begin(), *top_x.rbegin())) {
                auto best_st = *st.begin();
                st.erase(best_st);
                
                auto worst_top = *top_x.rbegin(); 
                top_x.erase(worst_top);

                top_x.insert(best_st);
                st.insert(worst_top);

                sum -= (long long)worst_top.first * worst_top.second;
                sum += (long long)best_st.first * best_st.second;
            }

            res.push_back(sum);
        }
        return res;
    }
};