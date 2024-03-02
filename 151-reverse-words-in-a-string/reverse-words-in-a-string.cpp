class Solution {
public:
    string reverseWords(string s) {
    string temp;
    vector<string> result;
    for(char i : s){
        if( i == ' '){
            if(!temp.empty()){
                result.push_back(temp);
                temp.clear();
            }
        }
        else{
            temp.push_back(i);
        }
    }
    if(!temp.empty()) result.push_back(temp);
reverse(result.begin(),result.end());
string ans;
for(string i : result){
    if(ans.empty()){
        ans = i;
    }
    else{
        ans += " " + i;
    }
}
return ans;

}

};