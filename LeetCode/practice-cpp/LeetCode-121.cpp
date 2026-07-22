// 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int profit = 0;
        int minPrice = prices[0];

        for (auto& price : prices) {
            if (price < minPrice) {
                minPrice = price; // 更新最小值
            } else {
                profit = max(profit, price - minPrice); // 更新最大利润
            }
        }
        return profit;
    }
};