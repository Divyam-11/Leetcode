class Solution {
public:
    bool canPlace(int mid, int d, vector<int> &start) {
        long long prev = start[0];

        for (int i = 1; i < start.size(); i++) {
            long long next;

            // Case 1: placing at least 'mid' away from previous
            if (prev + mid <= start[i]) {
                // can't start before its allowed window, so move to start[i]
                next = start[i];
            } 
            else {
                // can place at exactly prev + mid
                next = prev + mid;
            }

            // If placement exceeds window limit, it's invalid
            if (next > start[i] + d) {
                return false;
            }

            prev = next;
        }

        return true;
    }

    int maxPossibleScore(vector<int> &start, int d) {
        long long ans = 0;
        sort(start.begin(), start.end());

        long long low = 0;
        long long high = start.back() + d - start[0];

        while (low <= high) {
            int mid = low - (low - high) / 2;

            if (canPlace(mid, d, start)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
