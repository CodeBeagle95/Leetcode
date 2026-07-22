// 正则表达式匹配
class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = p.size(), m = s.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*' && i > 1) {
                    dp[i][0] = dp[i - 2][0]; // 单独处理首列跳过整个通配符
                    if (p[i - 2] == '.') {
                        dp[i][j] = dp[i - 2][j] || dp[i][j - 1]; // 跳过或继承
                    } else{
                        dp[i][j] = dp[i - 2][j] || (dp[i][j - 1] && p[i - 2] == s[j - 1]); // // 跳过或匹配继承
                    }
                }
            }
        }
        return dp[n][m];
    }
};