class Solution {
public:
    int maxLen = 0;
    bool valid(string s) {
        int open = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                if (open == 0)
                    return false;

                open--;
            }
        }

        return open == 0;
    }
    void check(int idx, string &temp, string &main, set<string>& st) {
        if (idx == main.size()) {
            if (temp.size() >= maxLen && valid(temp)) {
                maxLen = temp.size();
                st.insert(temp);
            }
            return;
        }
        // pick
        temp.push_back(main[idx]);
        check(idx + 1, temp, main, st);
        temp.pop_back();
        if(main[idx] == '(' || main[idx] == ')')
        check(idx+1, temp, main, st);
        
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        string temp;
        set<string> st;
        check(0, temp, s, st);
        for (auto it : st) {
            if (it.size() == maxLen)
                result.push_back(it);
        }
        return result;
    }
};