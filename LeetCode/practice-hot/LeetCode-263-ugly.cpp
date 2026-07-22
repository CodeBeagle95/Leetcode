// 丑数 - 只包含质因数 2、3 和 5 的 正 整数
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        while (n != 1) {
            int next = n;
            if (next % 2 == 0) next = next / 2;
            if (next % 3 == 0) next = next / 3;
            if (next % 5 == 0) next = next / 5;
            if (next == n) break;
            n = next;
        }
        return n == 1; // 1 也是丑数
    }
};