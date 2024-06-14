class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0;
        int r = 0 ;
string s;
while(r<chars.size()){
    s.push_back(chars[r]);
    while(r < chars.size() && chars[r] == chars[l]){
        r++;
    }
    int length = r-l;
    if(length > 1){
        s  = s + to_string(length);
    }
    l = r;

}
chars.clear();

for(int i = 0 ; i  < s.size();i++){
chars.push_back(s[i]);
}
return s.size();
    }
};