class Solution {
public:
    bool isValid(string s) {
    bool check = true;
    stack<char> st;
    unordered_map<char, char> m = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for(char i : s){
        if(i == '(' || i == '{' || i == '['){
            st.push(i);

        }
        else{
            if(st.empty()) return false;
            char temp = st.top();
            st.pop();
            if(m[i] != temp){
                return false;

            }
            
            
        }

    }
       
    return st.empty();
    }
};