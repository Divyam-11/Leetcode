class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int iceCreams=0;
     vector<int> mp(1e5+1);
     for(int i = 0 ;i < costs.size();i++){
        mp[costs[i]]++;
     }   
     for(int i = 1 ;i < mp.size();i++){
        if(i * 1LL* mp[i] <= 1LL*coins){
            iceCreams+=mp[i];
            coins-=i*mp[i];
        }
        else{
            int limit = coins/i;
            iceCreams+=limit;
            coins -=limit * mp[i];
            return iceCreams;
        }
     }
     return iceCreams;
    }
};