// 最小路径和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = (n == 0) ? 0 : grid[0].size();
        if (n == 0 || m == 0) return 0;

        vector<int> prevSum(m, INT_MAX);
        prevSum[0] = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> nextSum = grid[i];
            for (int j = 0; j < m; ++j) { // 需要从左往右更新
                nextSum[j] += min(prevSum[j], ((j == 0) ? INT_MAX : nextSum[j - 1]));
            }
            prevSum = nextSum;
        }
        return prevSum.back();
    }
};