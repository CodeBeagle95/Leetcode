// 有效的括号
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // 使用栈来解决
        for (auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
                continue;
            }

            if (stk.empty()) { // 先判断栈是否为空
                return false;
            }

            if (c == ')' && stk.top() == '(' ||
                c == '}' && stk.top() == '{' ||
                c == ']' && stk.top() == '[') {
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty(); // 最后判断栈是否为空
    }
};