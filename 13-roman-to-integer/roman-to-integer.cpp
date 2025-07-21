class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char x = s.at(i);

            // Check if it's safe to access s[i+1]
            if (i + 1 < s.length()) {
                switch (x) {
                    case 'I':
                        if (s.at(i + 1) == 'V' || s.at(i + 1) == 'X') {
                            num -= 1;
                        } else {
                            num += 1;
                        }
                        break;
                    case 'V':
                        num += 5;
                        break;
                    case 'X':
                        if (s.at(i + 1) == 'L' || s.at(i + 1) == 'C' || s.at(i + 1) == 'M') {
                            num -= 10;
                        } else {
                            num += 10;
                        }
                        break;
                    case 'L':
                        num += 50;
                        break;
                    case 'C':
                        if (s.at(i + 1) == 'D' || s.at(i + 1) == 'M') {
                            num -= 100;
                        } else {
                            num += 100;
                        }
                        break;
                    case 'D':
                        num += 500;
                        break;
                    case 'M':
                        num += 1000;
                        break;
                    default:
                        cout << "Invalid character found at " << i << endl;
                        break;
                }
            } else {
                // Handle the last character in the string
                switch (x) {
                    case 'I':
                        num += 1;
                        break;
                    case 'V':
                        num += 5;
                        break;
                    case 'X':
                        num += 10;
                        break;
                    case 'L':
                        num += 50;
                        break;
                    case 'C':
                        num += 100;
                        break;
                    case 'D':
                        num += 500;
                        break;
                    case 'M':
                        num += 1000;
                        break;
                    default:
                        cout << "Invalid character found at " << i << endl;
                        break;
                }
            }
        }
        return num;
    }
};
