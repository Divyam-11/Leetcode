class Solution {
    private:
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(),potions.end());
        for(int i = 0 ; i < spells.size();i++){
            int temp = 0;
            // for(int j = 0 ; j < potions.size();j++){
            //     long long int product =(long long int)spells[i] * (long long int)potions[j];
            //     if(product >= success){
            //         temp = potions.size() - j ;
            //         break;
            //     }
            // }
            int l = 0;
            int mid;
            int h = potions.size()-1;
            while(l<=h){
                mid = l + (h-l)/2;
                if((long long int)spells[i]*(long long int)potions[mid] >= success)
                    h = mid-1;
                
                else
                    l = mid+1;
            }
            result.push_back(potions.size()-1-h);
        }
        return result;
    }
};