// 买卖股票的最佳时机III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int buy1 = INT_MAX, profit1 = 0;
        int buy2 = INT_MAX, profit2 = 0;
        for (auto& price : prices) {
            buy1 = min(buy1, price); // 以最低价买入
            profit1 = max(profit1, price - buy1); // 高价差卖出
            buy2 = min(buy2, price - profit1); // 低价买入，同时把第一次收入计算在内
            profit2 = max(profit2, price - buy2); // 高价差卖出
        }
        return profit2;
    }
};