// 找到字符串中所有字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return vector<int>();
        }
        
        unordered_map<char, int> charCounter;
        for (auto& c : p) {
            ++charCounter[c];
        }

        int startIndex = 0;
        vector<int> result;
        unordered_map<char, queue<int>> matchIndex;

        for (int i = 0; i < s.size(); ++i) {
            auto findPattern = charCounter.find(s[i]); // 先查找匹配模版
            if (findPattern == charCounter.end()) {    // 模版中无此字符
                startIndex = i + 1;                    // 更新起始索引
                matchIndex.clear();                    // 重置匹配字典
                continue;
            }

            auto findMatch = matchIndex.find(s[i]);
            if (findMatch == matchIndex.end()) {      // 首次匹配该字符
                matchIndex[s[i]] = queue<int>();      // 初始化索引队列
                findMatch = matchIndex.find(s[i]);
            } 
            if (findMatch->second.size() < findPattern->second) {
                findMatch->second.push(i);            // 压入字符的索引
            } else {                                  // 字符数量超限制
                int index = findMatch->second.front();
                for (int j = startIndex; j <= index; ++j) {
                    auto findForRemove = matchIndex.find(s[j]);
                    assert(findForRemove != matchIndex.end() && findForRemove->second.size() > 0);
                    findForRemove->second.pop();
                }
                findMatch->second.push(i);            // 压入字符的索引
                startIndex = index + 1;               // 更新起始索引
            }
            
            if (i - startIndex + 1 == p.size()) {
                result.emplace_back(startIndex);
            }
        }
        return result;
    }
};