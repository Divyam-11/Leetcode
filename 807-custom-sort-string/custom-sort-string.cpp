class Solution {
public:
    string customSortString(string order, string s) {
      string result;
    unordered_map<char,int> m;
    for(char &i:s){
      m[i]++;
    }      
    for(char &i:order){
    auto it = m.find(i);
    if(it != m.end()){
      for(int j = 0;j<it->second;j++){
        result.push_back(i);
      }
      it->second = 0;

    }
    }
    for(auto &p:m){
      for(int i = 0 ;i<p.second;i++){
       result.push_back(p.first);
      }
    }
return result;
    }
};