class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(auto i : word){
            freq[i-'a']++;
        }
        int cost = 0;
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i = 0 ;i < 26;i++){
            cost = cost + ((i/8)+1) * freq[i];
        }
return cost;
    }
};