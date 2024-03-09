class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> m;
    for(int i : nums1){
    m[i]++;
    }
    for(int i : nums2){
      if(m.find(i) != m.end()){
      return i;
      }
    }
    return -1;
}
};