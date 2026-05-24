class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int sell = 0;
        int maxProfit = 0;
        for (int buy = 0; buy < prices.size() - 1; buy++) {
            if (buy >= sell) {
                sell = buy + 1;
                int maxSell = 0;
                int maxSellIndex = sell;
                while (sell < prices.size()) {
                    if (prices[sell] > maxSell) {
                        maxSell = prices[sell];
                        maxSellIndex = sell;
                    }
                    sell++;
                }
                sell = maxSellIndex;
            }
            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
        }
        return maxProfit;
    }
};
