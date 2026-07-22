// 最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int result = 0;
        vector<int> dp0(m, 0);

        for (int i = 0; i < n; ++i) {
            int maxElement = 0;
            vector<int> dp1(m, 0);
            for (int j = 0; j < m; ++j) {
                if (text1[i] == text2[j]) { // 当前元素匹配，则将先前序列的最大匹配数+1
                    dp1[j] = maxElement + 1;
                } else {
                    dp1[j] = dp0[j]; // 当前元素不匹配，则继承先前序列的匹配数
                }
                result = max(result, dp1[j]);
                maxElement = max(maxElement, dp0[j]);
            }
            dp0 = dp1;
        }
        return result;
    }
};