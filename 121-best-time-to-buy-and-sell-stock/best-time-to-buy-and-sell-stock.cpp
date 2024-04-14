class Solution {
public:
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < minPrice) {
            minPrice = prices[i]; // Update the minimum price if a smaller price is encountered
        } else {
            int currentProfit = prices[i] - minPrice; // Calculate potential profit if sold at current price
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit; // Update maximum profit if a better opportunity arises
            }
        }
    }
    
    return maxProfit;
}

};