// 字符串解码 - 注意嵌套
class Solution {
private:
    string duplicateString(int cnt, const string& str) {
        string result;
        result.reserve(cnt * str.size()); // 空间预分配
        while (cnt > 0) {
            -- cnt;
            std::copy(str.begin(), str.end(), back_inserter(result));
        }
        return result;
    }
    
public:
    string decodeString(string s) {
        int repeatCnt = 0;
        string repeatStr = "";
        stack<pair<int, string>> stk;

        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {                    // 处理数字
                if (i != 0 && !isdigit(s[i - 1])) { // 前一位非数字则出现嵌套
                    stk.push(make_pair(repeatCnt, repeatStr));
                    repeatCnt = 0;
                    repeatStr = "";
                }
                repeatCnt = 10 * repeatCnt + (s[i] - '0');
            } else if (s[i] == '[') {
                continue; // 无需特殊处理
            } else if (s[i] == ']') {
                repeatStr = (repeatCnt == 0)? repeatStr : duplicateString(repeatCnt, repeatStr);
                repeatCnt = 0;
                if (stk.empty()) {
                    continue;
                }
                
                auto [cnt, str] = stk.top();
                stk.pop();
                repeatStr = str + repeatStr;
                repeatCnt = cnt;
            } else {
                repeatStr += s[i];
            }
        }
        return repeatStr;
    }
};