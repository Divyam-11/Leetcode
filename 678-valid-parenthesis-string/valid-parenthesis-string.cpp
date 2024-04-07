class Solution {
public:
    bool checkValidString(string s) {
        int open_count = 0;
        int star_count = 0;

        // Scan from left to right
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

        // Reset counts for scanning from right to left
        open_count = 0;
        star_count = 0;

        // Scan from right to left
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
