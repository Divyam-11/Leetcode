class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long profit = 0, mn = INT_MAX;
        long long totalEnergy = currentEnergy;
        for(long long i = 0; i < enemyEnergies.size(); i++){
            if(enemyEnergies[i] < mn) mn = enemyEnergies[i];
            totalEnergy += enemyEnergies[i];
        }
        if(currentEnergy < mn) return 0;
        totalEnergy -= mn;
        return totalEnergy/mn;
    }
};