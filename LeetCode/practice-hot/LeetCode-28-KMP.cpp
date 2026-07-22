// 字符串匹配
// pattern: " aabaabac" -> 001012340
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 设置哨兵，简化代码逻辑，避免边界情况的特殊处理
        haystack = " " + haystack;
        needle = " " + needle;

        // 生成 next 数组
        int cur = 0;
        vector<int> next(needle.size(), 0);
        for (int i = 2; i < needle.size(); ++i) { // 跳过空格和首个数字
            while (cur > 0 && needle[i] != needle[cur + 1]) {
                cur = next[cur]; // 下一个字符无法匹配, 跳转到上一个索引
            }
            if (needle[i] == needle[cur + 1]) {
                ++cur;
            }
            next[i] = cur;
        }

        // 使用 next 数组辅助进行匹配
        cur = 0;
        for (int i = 1; i < haystack.size(); ++i) { // 跳过空格
            while (cur > 0 && haystack[i] != needle[cur + 1]) {
                cur = next[cur]; 
            }
            if (haystack[i] == needle[cur + 1]) {
                ++cur;
            }
            if (cur + 1 == needle.size()) { // 完全匹配
                return i - cur;
            }
        }
        return -1;  // 无法匹配
    }
};