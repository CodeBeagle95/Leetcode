// 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) {
            return string("");
        }

        unordered_map<char, int> diffCounter;
        for (auto& c : t) {
            ++ diffCounter[c];
        }

        int resIndex = -1;
        int minLen = INT_MAX;
        int counter = 0;  // 匹配计数
        int begIndex = 0; // 窗口起始索引
        int endIndex = 0; // 窗口尾后索引

        while (endIndex < s.size()) {
            // 右侧扩充，直到覆盖所有元素或遍历结束，注意越界保护
            while (counter < t.size() && endIndex < s.size()) {
                auto found = diffCounter.find(s[endIndex++]);
                if (found == diffCounter.end()) { // 非目标元素
                    continue;
                } else if (found->second <= 0) {  // 冗余目标元素
                    -- found->second;             // 记录冗余数量
                } else {                          // 非冗余目标元素
                    -- found->second;
                    ++counter;                    // 更新匹配计数
                }
            }
            // 左侧收缩，注意前提条件为计数与模版长度一致，避免遍历结束导致逻辑错误
            while (counter == t.size() && begIndex < endIndex) {
                auto found = diffCounter.find(s[begIndex++]);
                if (found == diffCounter.end()) { // 非目标元素
                    continue;
                } else if (found->second < 0) {   // 冗余目标元素
                    ++ found->second;
                } else if (found->second == 0) {  // 非冗余目标元素
                    if (endIndex - begIndex + 1 < minLen) {
                        minLen = endIndex - begIndex + 1;
                        resIndex = begIndex - 1;  // 注意索引回退
                    }
                    ++ found->second;
                    -- counter;                   
                    break;
                }
            }
        }
        return resIndex == -1 ? string("") : s.substr(resIndex, minLen);;
    }
};
