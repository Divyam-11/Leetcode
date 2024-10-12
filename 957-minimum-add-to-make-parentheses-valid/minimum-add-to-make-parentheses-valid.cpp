class Solution {
public:
    int minAddToMakeValid(string s) {
    stack<int> st;
    int res=0;
    for(int i = 0 ;i < s.size();i++){
        if(s[i] == '('){
        st.push('(');
        }
        else {
            if(st.empty()){
                res++;
            }
            else
            st.pop();
        }

    }      
    while(!st.empty()){
        st.pop();
        res++;
    }
    return res;
    }
};