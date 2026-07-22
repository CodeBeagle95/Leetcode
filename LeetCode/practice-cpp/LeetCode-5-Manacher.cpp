// 最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        string str(2 * s.size() + 1, '#');
        for (int i = 0; i < s.size(); ++i) {
            str[2 * i + 1] = s[i];
        }
        
        vector<int> armLens(str.size(), 0);
        int bestCenter = 0, bestArmLen = -1; // 记录最大回文窗口
        int currCenter = 0, currArmLen = -1; // 记录当前回文窗口

        for (int i = 0; i < str.size(); ++i) {
            int armLen = 0;
            if (i > currCenter + currArmLen) { // 索引在臂长边界外，直接中心探索
                // armLen = 0;
            } else if (i + armLens[2 * currCenter - i] <= currCenter + currArmLen) { // 索引在臂长边界内，加上对称位置臂长也在臂长边界内
                armLen = armLens[2 * currCenter - i];
            } else { // 索引在臂长边界内，加上对称位置臂长在臂长边界外
                armLen = currCenter + currArmLen - i;
            }

            while (i - armLen - 1 >= 0 && i + armLen + 1 < str.size() &&
                   str[i - armLen - 1] == str[i + armLen + 1]) {
                ++ armLen;
            }
            armLens[i] = armLen;

            if (i + armLen > currCenter + currArmLen) { // 更新臂长可达的最大索引和中心
                currCenter = i;
                currArmLen = armLen;
            }
            if (armLen > bestArmLen) { // 更新最大臂长和中心
                bestCenter = i;
                bestArmLen = armLen;
            }
        } 
        return s.substr((bestCenter - bestArmLen) / 2, bestArmLen);
    }
};