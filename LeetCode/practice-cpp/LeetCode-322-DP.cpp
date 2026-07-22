// 零钱兑换
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0 || coins.empty()) return -1;

        vector<int> dp(amount + 1, INT_MAX); // vector 相比 unordered_map 需要更少耗时和内存
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int counter = INT_MAX;
            for (auto& coin : coins) {
                if (i - coin >= 0) {
                    counter = min(counter, dp[i - coin]);
                }
            }
            if (counter != INT_MAX) {
                dp[i] = counter + 1;
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};