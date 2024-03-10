class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int,int> m;
  vector<int> result;
  for(auto &i: nums1){
  m[i]++;

  }
  for(auto &i:nums2){
    auto it = m.find(i);
    if(it != m.end()){
    result.push_back(it->first);
    m.erase(it->first);
    }
  }    
return result;
    }
};