// 字符串转换整数 (atoi)
class Solution {
private:
    string state = "start"; //0:空格, 1:符号, 2:数字, 3:结尾
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "number", "end"}},
        {"signed", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}}
    };
    long long ans = 0, sign = 1;

    int checkChar(const char &c) {
        if (c == ' ') return 0;
        if (c == '+' || c == '-') {
            if (state == "start") sign = (c == '+') ? 1 : -1;
            return 1;
        }
        if (c >= '0' && c <= '9') {
            ans = ans * 10 + (c - '0');
            if (sign == 1 && ans >= INT_MAX) {
                ans = INT_MAX;
                return 3;
            }
            if (sign == -1 && ans >= INT_MAX + 1) {
                ans = INT_MAX + 1;
                return 3;
            }
            return 2;
        }
        return 3;
    }

public:
    int myAtoi(string str) {
        for(auto &c : str){
            state = table[state][checkChar(c)];
            if(state == "end") break;
        }
        return sign * ans;
    }
};