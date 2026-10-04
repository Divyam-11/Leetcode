class Solution {
public:
    bool checkValidString(string s) {
        int open_count = 0;
        int star_count = 0;

        for (char c : s) {
            if (c == '(') {
                open_count++;
            } else if (c == ')') {
                if (open_count > 0) {
                    open_count--;
                } else if (star_count > 0) {
                    star_count--;
                } else {
                    return false;
                }
            } else if (c == '*') {
                star_count++;
            }
        }

        open_count = 0;
        star_count = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ')') {
                open_count++;
            } else if (c == '(') {
                if (open_count > 0) {
                    open_count--;
                } else if (star_count > 0) {
                    star_count--;
                } else {
                    return false;
                }
            } else if (c == '*') {
                star_count++;
            }
        }

        return true;
    }
};