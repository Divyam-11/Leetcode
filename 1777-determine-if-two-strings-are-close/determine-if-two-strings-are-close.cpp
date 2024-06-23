class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if(word1.size() != word2.size() ) return false;
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (int i = 0; i < word1.size(); i++)
        {
            freq1[word1[i]]++;
        }
        for (int i = 0; i < word2.size(); i++)
        {
            freq2[word2[i]]++;
        }
        if (freq1 == freq2)
        {
            return true;
        }
        vector<int> nums1;
        vector<int> nums2;
        for(char i ='a'; i<='z';i++){
            if(freq1[i] != 0 && freq2[i] != 0) continue;
            if(freq1[i] == 0 && freq2[i] == 0) continue;
            return false;
        }
        for(auto &i : freq1){
            nums1.push_back(i.second);
        }
        for(auto &i:freq2){
            nums2.push_back(i.second);
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1 == nums2) return true;
        return false;
    }
};