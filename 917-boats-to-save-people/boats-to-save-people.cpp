class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boat= 0;
        int l = 0;
        int r = people.size() -1;
        while(l<=r){
            int sum = people[l] + people[r];
            if(sum <= limit ){
                people[l] *=-1;
                people[r] *=-1;
                l++;
                r--;
                boat++;

            }
            else{
                r--;
                boat++;
            }

        }
        return boat;
    }
};
