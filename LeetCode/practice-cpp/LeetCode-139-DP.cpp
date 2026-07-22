// 单词拆分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (auto& word : wordDict) {
                int len = word.size();
                if (i - len >= 0 && s.substr(i - len, len) == word) {
                    dp[i] = dp[i] || dp[i - len]; // 或运算
                }
            }
        }
        return dp.back();
    }
};