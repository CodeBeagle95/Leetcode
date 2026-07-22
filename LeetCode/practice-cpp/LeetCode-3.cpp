// 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char, int> charIndex;                 // k:字符-v:索引

        int startIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto find = charIndex.find(s[i]);
            if (find == charIndex.end()) {                  // if 没有重复字符
                longest = max(longest, i - startIndex + 1); // 更新结果
                charIndex[s[i]] = i;                        // 更新字典
            } else {                                        // else 有重复字符
                longest = max(longest, i - startIndex);     // 更新结果
                for (int j = startIndex; j < find->second; ++j) {
                    charIndex.erase(s[j]);                  // 从字典删除部分字符
                }
                startIndex = find->second + 1;              // 更新起始索引
                charIndex[s[i]] = i;                        // 更新字典
            }
        }
        return longest;
    }
};
