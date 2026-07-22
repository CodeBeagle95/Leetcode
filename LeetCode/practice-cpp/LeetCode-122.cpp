// 买卖股票的最佳时机II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int profit = 0;
        int buy = prices[0];

        for (auto& price : prices) {
            if (price > buy) {
                profit += price - buy;
                buy = price;
            } else {
                buy = price;
            }
        }
        return profit;
    }
};