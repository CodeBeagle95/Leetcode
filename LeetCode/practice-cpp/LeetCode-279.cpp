// 完全平方数
class Solution {
public:
    int numSquares(int n) { // 动态规划
        if (n <= 0) return 0;
        vector<int> fn(n + 1);
        for (int i = 1; i <= n; ++i) {
            int counter = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                counter = min(fn[i - j * j], counter);
            }
            fn[i] = counter + 1;
        }
        return fn[n];
    }
};