class RandomizedSet
{
public:
    vector<int> nums;
    unordered_map<int, int> mp;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) == mp.end())
        {
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (mp.find(val) != mp.end())
        {   mp[nums.back()] = mp[val];
            swap(nums[mp[val]], nums[nums.size() - 1]);
            nums.pop_back();
            
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};
