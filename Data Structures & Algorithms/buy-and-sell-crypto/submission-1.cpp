class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int maxProfit = 0;
        for (int p : prices) {
            min_buy = min(min_buy, p);
            maxProfit = max(maxProfit, p - min_buy);
        }
        return maxProfit;
    }
};
