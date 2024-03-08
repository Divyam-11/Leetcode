class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int,int> freq;
    for(int &i:nums){
        freq[i]++;
    }
    int result = 0;
    int max_freq = INT_MIN;
    for(auto &i:freq){
        max_freq = max(max_freq,i.second);

    }
    for(auto i:freq){
        if(i.second == max_freq){
            result+=max_freq;
        }
    }
    return result;
    }
};