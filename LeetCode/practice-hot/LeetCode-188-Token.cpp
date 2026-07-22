// 买卖股票的最佳时机 IV - 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.empty()) return 0;

        vector<int> buy(k, INT_MAX);
        vector<int> profit(k, INT_MIN);

        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 0; j < k; ++j) {
                buy[j] = min(buy[j], prices[i] - ((j == 0) ? 0 : profit[j - 1])); // 低价买入，同时把前面的收入归纳在内
                profit[j] = max(profit[j], prices[i] - buy[j]); // 高价差卖出
            }
        }
        return profit.back();
    }
};