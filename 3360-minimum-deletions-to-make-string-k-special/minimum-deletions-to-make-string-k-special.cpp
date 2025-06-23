class Solution {
public:
    int minimumDeletions(string word, int k) {

        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }


        int mx = *max_element(freq.begin(), freq.end());
        int n = word.size();
        int best = n;  
        for (int L = 0; L <= mx; ++L) {
            int R = L + k;
            int deletions = 0;

            for (int f : freq) {
                if (f < L) {
                    deletions += f;
                } else if (f > R) {
                    deletions += (f - R);
                }
            }

            best = min(best, deletions);
        }

        return best;
    }
};
