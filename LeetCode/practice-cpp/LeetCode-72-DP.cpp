// 编辑距离
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;

        vector<int> dp0(m + 1, 0);
        for (int i = 1; i <= n; ++i) {
            vector<int> dp1(m + 1, i); // 第 i 行初始化为 i
            for (int j = 1; j <= m; ++j) {
                int left = dp1[j - 1];
                int down = (i == 1) ? j : dp0[j];
                int left_down = (i == 1) ? j - 1 : dp0[j - 1];
                dp1[j] = min(min(left + 1, down + 1), left_down + (word1[i - 1] != word2[j - 1])); // 注意这里使用的索引
            }
            dp0 = dp1;
        }
        return dp0.back();
    }
};
