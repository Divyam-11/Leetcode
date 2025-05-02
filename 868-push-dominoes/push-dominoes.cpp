#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        while (true) {
            string new_dominoes = dominoes;

            int pos = 0;
            while ((pos = new_dominoes.find("R.L", pos)) != -1) {
                new_dominoes.replace(pos, 3, "S");
                pos += 1;
            }

            pos = 0;
            while ((pos = new_dominoes.find(".L", pos)) != -1) {
                new_dominoes.replace(pos, 2, "LL");
                pos += 2;
            }

            pos = 0;
            while ((pos = new_dominoes.find("R.", pos)) != -1) {
                new_dominoes.replace(pos, 2, "RR");
                pos += 2;
            }

            if (new_dominoes == dominoes)
                break;
            else
                dominoes = new_dominoes;
        }

        int pos = 0;
        while ((pos = dominoes.find("S", pos)) != -1) {
            dominoes.replace(pos, 1, "R.L");
            pos += 3;
        }

        return dominoes;
    }
};
