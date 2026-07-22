// 整数反转
class Solution {
public:
    int reverse(int x) {
        if (x < 0) {
            return (x == INT_MIN) ? 0 : -reverse(-x); // 保证后续处理的都是零或正数
        };

        int result = 0;
        while (x > 0) {
            int tailNum = x % 10;
            if (result > INT_MAX / 10 || result == INT_MAX / 10 && tailNum > INT_MAX % 10) {
                return 0;
            }
            result = result * 10 + tailNum;
            x /= 10;
        }
        return result;
    }
};